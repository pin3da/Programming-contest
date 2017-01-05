from collections import OrderedDict

dic = OrderedDict()
n = int(input())
for _ in range(n):
    line = input().split()
    name = ' '.join(line[:-1])
    price = line[-1:][0]
    if (not name in dic):
        dic[name] = 0
    price = int(price)
    dic[name] += price

for k in dic:
    print (k, dic[k])
