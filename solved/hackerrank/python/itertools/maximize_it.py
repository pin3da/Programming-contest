from itertools import product

k, mod = map(int, input().split())
l = []
for i in range(k):
    n, *s = map(int, input().split())
    l.append(s)
it = product(*l)

best = -1
for i in it:
    best = max(best, sum(map(lambda x: x*x, i)) % mod)
print (best)
