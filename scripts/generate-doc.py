import xml.etree.ElementTree as ET
import sys

def xml_to_markdown_array(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()

    md_lines = []
    header = "| Name | Key | Min Arity | Max Arity | Details |"
    separator = "|------|-----|-----------|-----------|---------|"
    md_lines.append(header)
    md_lines.append(separator)

    for op in root.findall('Operation'):
        name = op.attrib.get('name', '')
        key = op.attrib.get('key', '')
        min_arity = op.attrib.get('min_arity', '')
        max_arity = op.attrib.get('max_arity', '')
        if max_arity == '-1':
            max_arity = '∞'
        if min_arity == '-1':
            min_arity = '∞'
        operation = op.attrib.get('cpp_op', '')
        details = op.attrib.get('details', '')
        if not details and "std::" in operation:
            details = f'c.f. `{operation}`'
        line = f"| {name} | `{key}` | {min_arity} | {max_arity} | {details} |"
        md_lines.append(line)

    return md_lines

if __name__ == "__main__":
    if len(sys.argv) > 1:
        xml_filepath = sys.argv[1]
    else:
        print("Usage: python {} <xml_filepath>".format(sys.argv[0]))
        sys.exit(1)

    markdown_lines = xml_to_markdown_array(xml_filepath)
    for line in markdown_lines:
        print(line)
