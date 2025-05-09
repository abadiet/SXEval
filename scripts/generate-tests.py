import sys
import xml.etree.ElementTree as ET

TEMPLATE='''
#include <catch2/catch_test_macros.hpp>
#include <sxeval/operations/Operations.hpp>
#include <sxeval/AInstruction.hpp>
#include <sxeval/Value.hpp>
{includes}

using namespace sxeval;

TEST_CASE("Operations instanciation", "[operations]") {{
    AInstruction<int>* instr = dynamic_cast<AInstruction<int>*>(
        new Value<int>(0));
    std::vector<AInstruction<int>*> args1;
    args1.push_back(instr);
    std::vector<AInstruction<int>*> args2;
    args2.push_back(instr);
    args2.push_back(instr);
    std::vector<AInstruction<int>*> args3;
    args3.push_back(instr);
    args3.push_back(instr);
    args3.push_back(instr);

{tests_instanciations}
    delete instr;
}}

TEST_CASE("Mathematical tests", "[operations]") {{

{tests_math}
}}

'''

def generate(operations, mathematical_tests, output_path):
    includes = "\n".join([f"#include <sxeval/operations/{op[0]}.hpp>" for op in operations])

    tests_instanciations = ""
    for op in operations:
        name = op[0]
        key = op[1]
        arity_min = int(op[2])
        arity_max = int(op[3])
        if arity_min <= 1 and (arity_max == -1 or arity_max >= 1):
            tests_instanciations += '''    REQUIRE(nullptr != dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", args1).get()));
'''.format(name, key)
        elif arity_min <= 2 and (arity_max == -1 or arity_max >= 2):
            tests_instanciations += '''    REQUIRE(nullptr != dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", args2).get()));
'''.format(name, key)
        elif arity_min <= 3 and (arity_max == -1 or arity_max >= 3):
            tests_instanciations += '''    REQUIRE(nullptr != dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", args3).get()));
'''.format(name, key)
        else:
            tests_instanciations += '''    REQUIRE(nullptr != dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", /* args */).get()));
'''.format(name, key)
    
    tests_math = ""
    for op in mathematical_tests:
        name = op[0]
        key = op[1]
        tests_math += f'    SECTION("{name}") {{\n'
        for test in op[2]:
            type = test[0]
            args = test[1]
            result = test[2]
            tests_math += f'        {{\n        {type} rawArgs[{len(args)}] = {{{",".join(args)}}};\n'
            instr_lst = []
            for i in range(len(args)):
                tests_math += f'''        AInstruction<{type}>* instr{i} = dynamic_cast<AInstruction<{type}>*>(
        new Value<{type}>(rawArgs[{i}]));\n'''
                instr_lst.append(f'instr{i}')
            tests_math += f'        std::vector<AInstruction<{type}>*> args = {{{", ".join(instr_lst)}}};\n'
            tests_math += f'        auto op = operations::Operations<{type}>::create("{key}", args);\n'
            tests_math += '        op->execute();\n'
            tests_math += f'        REQUIRE({result} == op->getResult());\n'
            for i in range(len(args)):
                tests_math += f'        delete instr{i};\n'
            tests_math += '        }\n'
        tests_math += '    }\n'

    content = TEMPLATE.format(includes=includes, tests_instanciations=tests_instanciations, tests_math=tests_math)

    output_path = f"{output_path}/TestOperations.cpp"
    with open(output_path, "w") as f:
        f.write(content)
    print(f"Generated {output_path}")

if __name__ == "__main__":
    if len(sys.argv) > 3:
        operations_file = sys.argv[1]
        mathematical_tests_file = sys.argv[2]
        output_path = sys.argv[3]
    else:
        print("Usage: python {} <operations_filepath> <mathematical_tests_filepath> <output_path>".format(sys.argv[0]))
        sys.exit(1)

    tree = ET.parse(operations_file)
    root = tree.getroot()
    operations = []
    for op in root.findall('Operation'):
        name = op.attrib.get('name', '')
        key = op.attrib.get('key', '')
        min_arity = op.attrib.get('min_arity', '')
        max_arity = op.attrib.get('max_arity', '')
        operation = op.attrib.get('cpp_op', '')
        operations += [[name, key, min_arity, max_arity, operation]]

    tree = ET.parse(mathematical_tests_file)
    root = tree.getroot()
    mathematical_tests = []
    for op in root.findall('Operation'):
        name = op.attrib.get('name', '')
        key = op.attrib.get('key', '')
        mathematical_tests += [[name, key, []]]
        for test in op.findall('Test'):
            type = test.attrib.get('type', '')
            args = test.attrib.get('args', '').split(',')
            result = test.attrib.get('result', '')
            mathematical_tests[-1][2].append([type, args, result])

    generate(operations, mathematical_tests, output_path)
