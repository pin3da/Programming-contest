from collections import OrderedDict

n = int(input())
frec = OrderedDict()
for _ in range(n):
    w = input()
    if (not w in frec):
        frec[w] = 0
    frec[w] += 1
print(len(frec))
for i in frec:
    print(frec[i], end=' ')
