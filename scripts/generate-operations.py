import sys
import xml.etree.ElementTree as ET

TEMPLATE_OP = '''#ifndef {include_guard}
#define {include_guard}

#include "sxeval/AOperation.hpp"
{includes}

/* DEFINITIONS */

namespace sxeval {{
namespace operations {{

template <typename T>
class Operations;

template <typename T>
class {class_name} : public AOperation<T> {{
public:
    void execute() override;

protected:
    static constexpr const char *KEY = "{key}";
    static constexpr const int ARITY_MIN = {arity_min};
    static constexpr const int ARITY_MAX = {arity_max};

    inline {class_name}(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {{}}

    friend class Operations<T>;

}};

}} /* namespace operations */
}} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
void sxeval::operations::{class_name}<T>::execute() {{
    {execute}
}}

#endif /* {include_guard} */
'''

TEMPLATE_FACTORY='''
#ifndef SXEVAL_OPERATIONS_HPP
#define SXEVAL_OPERATIONS_HPP

#include "sxeval/AOperation.hpp"
{include_ops}
#include <vector>
#include <memory>


/* DEFINITIONS */

namespace sxeval {{
namespace operations {{

template <typename T>
class Operations {{
public:
    static constexpr const int UNLIMITED_ARITY = -1;

    Operations() = delete;
    Operations(const Operations&) = delete;
    Operations& operator=(const Operations&) = delete;
    Operations(Operations&&) = delete;
    Operations& operator=(Operations&&) = delete;
    ~Operations() = delete;

    static std::unique_ptr<AOperation<T>> create(const std::string& key,
        const std::vector<AInstruction<T>*> args);

private:
    static void checkArity(const std::string& key, int nArgs, int arityMin,
        int arityMax);

}};

}} /* namespace operations */
}} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>
std::unique_ptr<sxeval::AOperation<T>>
sxeval::operations::Operations<T>::create(
    const std::string& key, const std::vector<sxeval::AInstruction<T>*> args)
{{
    {create}
    throw std::invalid_argument("Unknown operation key: " + key);
}}

template <typename T>
void sxeval::operations::Operations<T>::checkArity(const std::string& key,
    int nArgs, int arityMin, int arityMax)
{{
    if (nArgs < arityMin) {{
        throw std::invalid_argument("Operation " + key + " requires at least "
            + std::to_string(arityMin) + " arguments");
    }}
    if (arityMax != UNLIMITED_ARITY && nArgs > arityMax) {{
        throw std::invalid_argument("Operation " + key + " requires at most "
            + std::to_string(arityMax) + " arguments");
    }}
}}

#endif /* SXEVAL_OPERATIONS_HPP */
'''


def generate_op(class_name, key, arity_min, arity_max, operation, output_path):
    include_guard = f"SXEVAL_OPERATIONS_{class_name.upper()}_HPP"
    execute = ""

    if operation == "":
        execute = "this->_result = "
    elif int(arity_min) == 1 and int(arity_max) == 1:
        execute = f"this->_result = static_cast<T>({operation}(this->_args.front()->getResult()));"
    elif int(arity_min) == 2 and int(arity_max) == 2:
        execute = f'''this->_result = static_cast<T>({operation}(this->_args.front()->getResult(),
        this->_args.back()->getResult()));'''
    elif int(arity_min) == 3 and int(arity_max) == 3:
        execute = f'''this->_result = static_cast<T>({operation}(this->_args.front()->getResult(),
        this->_args[1]->getResult(), this->_args.back()->getResult()));'''
    elif int(arity_max) == -1:
        if operation == "sxeval":
            execute = '''this->_result = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif && (i + 1) < this->_args.size()) {{
        verif = sxeval::{class_name}(this->_args[i]->getResult(),
            this->_args[i + 1]->getResult());
        ++i;
    }}
    if (verif) {{
        this->_result = static_cast<T>(1);
    }}
    else {{
        this->_result = static_cast<T>(0);
    }}'''.format(class_name=class_name)
        elif "::" in operation:
            execute = '''this->_result = this->_args.front()->getResult();
    for (size_t i = 1; i < this->_args.size(); ++i) {{
        this->_result = static_cast<T>({operation}(this->_result,
            this->_args[i]->getResult()));
    }}'''.format(operation=operation)
        elif operation != "":
            execute = '''this->_result = this->_args.front()->getResult();
    for (size_t i = 1; i < this->_args.size(); ++i) {{
        this->_result {operation}= this->_args[i]->getResult();
    }}'''.format(operation=operation)
    else:
        execute = "this->_result = "

    includes = ""
    if "std::" in operation:
        includes += "#include <cmath>\n"
    if "sxeval::" in operation or operation == "sxeval":
        includes += "#include \"sxeval/utils.hpp\"\n"

    content = TEMPLATE_OP.format(
        include_guard=include_guard,
        class_name=class_name,
        key=key,
        arity_min=arity_min if int(arity_min) >= 0 else "Operations<T>::UNLIMITED_ARITY",
        arity_max=arity_max if int(arity_max) >= 0 else "Operations<T>::UNLIMITED_ARITY",
        includes=includes,
        execute=execute
    )

    output_path = f"{output_path}/{class_name}.hpp"
    with open(output_path, "w") as f:
        f.write(content)

    print(f"Generated {output_path}")

def generate_factory(operations, output_path):
    include_ops = "\n".join([f"#include \"sxeval/operations/{op[0]}.hpp\"" for op in operations])
    create = '''if (key == sxeval::operations::{name}<T>::KEY) {{
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::{name}<T>::ARITY_MIN,
            sxeval::operations::{name}<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::{name}<T>>(
            sxeval::operations::{name}<T>(args));
'''.format(name=operations[0][0]) + "\n".join([f'''\t}} else if (key == sxeval::operations::{op[0]}<T>::KEY) {{
        checkArity(key, static_cast<int>(args.size()),
            sxeval::operations::{op[0]}<T>::ARITY_MIN,
            sxeval::operations::{op[0]}<T>::ARITY_MAX);
        return std::make_unique<sxeval::operations::{op[0]}<T>>(
            sxeval::operations::{op[0]}<T>(args));''' for op in operations[1:]]) + "\n\t}"
    content = TEMPLATE_FACTORY.format(include_ops=include_ops, create=create)

    output_path = f"{output_path}/Operations.hpp"
    with open(output_path, "w") as f:
        f.write(content)
    print(f"Generated {output_path}")


if __name__ == "__main__":
    if len(sys.argv) > 2:
        xml_file = sys.argv[1]
        output_path = sys.argv[2]
    else:
        print("Usage: python {} <xml_filepath> <output_path>".format(sys.argv[0]))
        sys.exit(1)

    tree = ET.parse(xml_file)
    root = tree.getroot()
    operations = []

    for op in root.findall('Operation'):
        name = op.attrib.get('name', '')
        key = op.attrib.get('key', '')
        min_arity = op.attrib.get('min_arity', '')
        max_arity = op.attrib.get('max_arity', '')
        operation = op.attrib.get('cpp_op', '')
        operations += [[name, key, min_arity, max_arity, operation]]

    for op in operations:
        class_name = op[0]
        key = op[1]
        arity_min = op[2]
        arity_max = op[3]
        operation = op[4]
        generate_op(class_name, key, arity_min, arity_max, operation, output_path)

    generate_factory(operations, output_path)
