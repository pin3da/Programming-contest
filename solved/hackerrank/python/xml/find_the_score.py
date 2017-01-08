def get_attr_number(node):
    ans = len(node.attrib)
    for child in node:
        ans += get_attr_number(child)
    return ans
