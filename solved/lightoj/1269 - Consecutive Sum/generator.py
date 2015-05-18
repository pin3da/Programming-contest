from random import *

tc = 10
print tc

for t in xrange(0, tc):
    n = randint(1, 10)
    print n,
    for j in xrange(0, n):
        print randint(1, 10),
    print ''

