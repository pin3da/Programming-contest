maxdepth = 0
def depth(elem, level):
    global maxdepth
    maxdepth = max(maxdepth, level + 1)
    for ch in elem:
        depth(ch, level + 1)
