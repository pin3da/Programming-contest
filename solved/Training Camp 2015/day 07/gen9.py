from random import *

tc = 2
print tc
for i in xrange(0, tc):
    n = randint(1, 10)
    print n
    for j in xrange(0, n):
        print randint(1, 10),
    print ""

