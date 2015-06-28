import random as r

tc = 15
maxn = 10 ** 5 + 1
maxk = 10 ** 6 + 1
maxl = 10 ** 8 + 1
print tc
for t in xrange(0, 15):
    n, k = r.randint(1, maxn), r.randint(1, maxk)
    print n, k
    for i in xrange(0, n):
        print r.randint(1, maxl),

