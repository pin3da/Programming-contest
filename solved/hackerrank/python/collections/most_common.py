from collections import OrderedDict, Counter

class MyMap(Counter, OrderedDict):
    pass


m = MyMap(sorted(input()))
for i in m.most_common(3):
    print (*i)
