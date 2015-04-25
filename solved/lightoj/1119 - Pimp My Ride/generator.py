from random import *

tc = 10
print tc

for k in xrange(0, tc):
    n = randint(1, 14)
    print n
    for i in xrange(0, n):
        for j in xrange(0, n):
            print randint(0, 100000),
        print ""
