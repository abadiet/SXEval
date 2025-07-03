import xml.etree.ElementTree as ET
import random
import argparse

encaps_var = []
normal_var = []

def parse_operations(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    operations = []

    for op in root.findall("Operation"):
        key = op.get("key")
        min_arity = int(op.get("min_arity"))
        max_arity = int(op.get("max_arity"))
        operations.append({
            "key": key,
            "min_arity": min_arity,
            "max_arity": max_arity
        })

    return operations

def generate_atom(ratio_value, ratio_encapsulated):
    if random.random() < ratio_value:
        return str(round(random.uniform(-100.0, 100.0), 2))
    else:
        if random.random() < ratio_encapsulated:
            i = random.randint(0, len(encaps_var))
            if i == len(encaps_var):
                encaps_var.append(f"e{i}")
            return encaps_var[i]
        else:
            i = random.randint(0, len(normal_var))
            if i == len(normal_var):
                normal_var.append(f"n{i}")
            return normal_var[i]

def generate_expression(operations, max_depth, max_arity, ratio_atom, ratio_value, ratio_encapsulated, current_depth=0):
    if current_depth > 0 and (current_depth >= max_depth or random.random() < ratio_atom):
        return generate_atom(ratio_value, ratio_encapsulated)

    op = random.choice(operations)
    min = op["min_arity"]
    max = op["max_arity"] if op["max_arity"] != -1 else max_arity
    arity = random.randint(min, max)

    args = [generate_expression(operations, max_depth, max_arity, ratio_atom, ratio_value, ratio_encapsulated, current_depth + 1) for _ in range(arity)]
    return f'({op["key"]} {" ".join(args)})'

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Random s-expression generator.")
    parser.add_argument("operations_xml", help="XML file containing operation definitions.")
    parser.add_argument("--count", type=int, default=1000, help="Number of expressions to generate.")
    parser.add_argument("--max-depth", type=int, default=10, help="Maximum recursion depth.")
    parser.add_argument("--max-arity", type=int, default=10, help="Maximum arity.")
    parser.add_argument("--ratio-atom", type=int, default=0.3, help="Atom/Operation ratio.")
    parser.add_argument("--ratio-value", type=int, default=0.5, help="Value/Variable ratio.")
    parser.add_argument("--ratio-encapsulated", type=int, default=0.5, help="Encaspulated/Normal variable ratio.")
    parser.add_argument("--out", type=str, default="expressions.lst", help="Output file. Console if not provided.")
    args = parser.parse_args()

    operations = parse_operations(args.operations_xml)

    for _ in range(args.count):
        encaps_var.clear()
        normal_var.clear()
        expr = generate_expression(
            operations,
            max_depth=args.max_depth,
            max_arity=args.max_arity,
            ratio_atom=args.ratio_atom,
            ratio_value=args.ratio_value,
            ratio_encapsulated=args.ratio_encapsulated
        )
        if args.out:
            with open(args.out, 'a') as f:
                f.write(expr + '\n')
        else:
            print(expr)
