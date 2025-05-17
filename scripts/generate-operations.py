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
class {class_name} : public AOperation<T> {{
public:
    static constexpr const char *KEY = "{key}";
    static constexpr const int ARITY_MIN = {arity_min};
    static constexpr const int ARITY_MAX = {arity_max};

    inline {class_name}(const std::vector<AInstruction<T>*>& args) :
        AOperation<T>(args) {{}}

    void execute() override;

    inline std::string toString() const override {{ return KEY; }}

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
{include}
#include <memory>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <functional>
#include <sstream>


/* DEFINITIONS */

namespace sxeval {{
namespace operations {{

template <typename T>
class OperationsFactory {{
public:
    OperationsFactory();

    template <typename OP>
    void add();

    std::unique_ptr<AOperation<T>> create(const std::string& key,
        const std::vector<AInstruction<T>*> args);

private:
    std::unordered_map<std::string,
        const std::function<std::unique_ptr<AOperation<T>>(
        const std::vector<AInstruction<T>*>&)>> _operations;

}};

}} /* namespace operations */
}} /* namespace sxeval */


/* IMPLEMENTATIONS */

template <typename T>

sxeval::operations::OperationsFactory<T>::OperationsFactory() {{
{add}
}}

template <typename T>
template <typename OP>
void sxeval::operations::OperationsFactory<T>::add() {{
    if constexpr (!(std::is_base_of<AOperation<T>, OP>::value)) {{
        throw std::invalid_argument("OP must be derived from AOperation");
    }}
    if (_operations.find(OP::KEY) != _operations.end()) {{
        _operations.erase(OP::KEY);
    }}
    const std::function<std::unique_ptr<AOperation<T>>(
        const std::vector<AInstruction<T>*>&)> f =
        [](const std::vector<AInstruction<T>*>& args) {{
            const auto nargs = static_cast<int>(args.size());
            if (nargs < OP::ARITY_MIN) {{
                std::ostringstream oss;
                oss << "Operation " << OP::KEY << " requires at least "
                    << OP::ARITY_MIN << " arguments";
                throw std::invalid_argument(oss.str());
            }}
            if (OP::ARITY_MAX != AOperation<T>::UNLIMITED_ARITY
                && nargs > OP::ARITY_MAX)
            {{
                std::ostringstream oss;
                oss << "Operation " << OP::KEY << " requires at most "
                    << OP::ARITY_MAX << " arguments";
                throw std::invalid_argument(oss.str());
            }}
            return std::make_unique<OP>(args);
        }};
    _operations.insert(std::make_pair(OP::KEY, f));
}}

template <typename T>
std::unique_ptr<sxeval::AOperation<T>>
sxeval::operations::OperationsFactory<T>::create(
    const std::string& key, const std::vector<sxeval::AInstruction<T>*> args)
{{
    const auto it = _operations.find(key);
    if (it == _operations.end()) {{
        throw std::invalid_argument("Unknown operation key: " + key);
    }}
    return it->second(args);
}}

#endif /* SXEVAL_OPERATIONS_HPP */
'''


def generate_op(class_name, key, arity_min, arity_max, operation, output_path):
    include_guard = f"SXEVAL_OPERATIONS_{class_name.upper()}_HPP"
    execute = ""

    if operation == "":
        execute = "this->getResult() = "
    elif int(arity_min) == 1 and int(arity_max) == 1:
        execute = f"this->getResult() = static_cast<T>({operation}(this->getArgs().front()->getResult()));"
    elif int(arity_min) == 2 and int(arity_max) == 2:
        execute = f'''this->getResult() = static_cast<T>({operation}(this->getArgs().front()->getResult(),
        this->getArgs().back()->getResult()));'''
    elif int(arity_min) == 3 and int(arity_max) == 3:
        execute = f'''this->getResult() = static_cast<T>({operation}(this->getArgs().front()->getResult(),
        this->getArgs()[1]->getResult(), this->getArgs().back()->getResult()));'''
    elif int(arity_max) == -1:
        if operation == "sxeval":
            execute = '''this->getResult() = static_cast<T>(1);
    size_t i = 0;
    bool verif = true;
    while (verif && (i + 1) < this->getArgs().size()) {{
        verif = sxeval::{class_name}(this->getArgs()[i]->getResult(),
            this->getArgs()[i + 1]->getResult());
        ++i;
    }}
    if (verif) {{
        this->getResult() = static_cast<T>(1);
    }}
    else {{
        this->getResult() = static_cast<T>(0);
    }}'''.format(class_name=class_name)
        elif "::" in operation:
            execute = '''this->getResult() = this->getArgs().front()->getResult();
    for (size_t i = 1; i < this->getArgs().size(); ++i) {{
        this->getResult() = static_cast<T>({operation}(this->getResult(),
            this->getArgs()[i]->getResult()));
    }}'''.format(operation=operation)
        elif operation != "":
            execute = '''this->getResult() = this->getArgs().front()->getResult();
    for (size_t i = 1; i < this->getArgs().size(); ++i) {{
        this->getResult() {operation}= this->getArgs()[i]->getResult();
    }}'''.format(operation=operation)
    else:
        execute = "this->getResult() = "

    includes = ""
    if "std::" in operation:
        includes += "#include <cmath>\n"
    if "sxeval::" in operation or operation == "sxeval":
        includes += "#include \"sxeval/utils.hpp\"\n"

    content = TEMPLATE_OP.format(
        include_guard=include_guard,
        class_name=class_name,
        key=key,
        arity_min=arity_min if int(arity_min) >= 0 else "AOperation<T>::UNLIMITED_ARITY",
        arity_max=arity_max if int(arity_max) >= 0 else "AOperation<T>::UNLIMITED_ARITY",
        includes=includes,
        execute=execute
    )

    output_path = f"{output_path}/{class_name}.hpp"
    with open(output_path, "w") as f:
        f.write(content)

    print(f"Generated {output_path}")

def generate_factory(operations, output_path):
    include = "\n".join([f"#include \"sxeval/operations/{op[0]}.hpp\"" for op in operations])
    add = "\n".join([f"    add<{op[0]}<T>>();" for op in operations])
    content = TEMPLATE_FACTORY.format(include=include, add=add)

    output_path = f"{output_path}/OperationsFactory.hpp"
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
