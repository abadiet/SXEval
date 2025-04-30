import sys
import xml.etree.ElementTree as ET

TEMPLATE='''
#include <catch2/catch_test_macros.hpp>
#include <sxeval/operations/Operations.hpp>
#include <sxeval/AInstruction.hpp>
{includes}

using namespace sxeval;

TEST_CASE("Operations instanciation", "[operations]") {{
    int argInt = 0;
    AInstruction<int>* instr = new AInstruction<int>(argInt);
    std::vector<AInstruction<int>*> args1;
    args1.push_back(instr);
    std::vector<AInstruction<int>*> args2;
    args2.push_back(instr);
    args2.push_back(instr);
    std::vector<AInstruction<int>*> args3;
    args3.push_back(instr);
    args3.push_back(instr);
    args3.push_back(instr);

    {requires}
    delete instr;
}}
'''

def generate(operations, output_path):
    includes = "\n".join([f"#include <sxeval/operations/{op[0]}.hpp>" for op in operations])
    requires = ""
    for op in operations:
        name = op[0]
        key = op[1]
        arity_min = int(op[2])
        arity_max = int(op[3])
        if arity_min <= 1 and (arity_max == -1 or arity_max >= 1):
            requires += '''REQUIRE(dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", args1).get()) != nullptr);
    '''.format(name, key)
        elif arity_min <= 2 and (arity_max == -1 or arity_max >= 2):
            requires += '''REQUIRE(dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", args2).get()) != nullptr);
    '''.format(name, key)
        elif arity_min <= 3 and (arity_max == -1 or arity_max >= 3):
            requires += '''REQUIRE(dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", args3).get()) != nullptr);
    '''.format(name, key)
        else:
            requires += '''REQUIRE(dynamic_cast<operations::{}<int>*>(
        operations::Operations<int>::create("{}", /* args */).get()) != nullptr);
    '''.format(name, key)
    content = TEMPLATE.format(includes=includes, requires=requires)

    output_path = f"{output_path}/TestOperations.cpp"
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

    generate(operations, output_path)
