from random import *

a = 10
print a

for i in xrange(a):
    print randint(1,30),


b = 10
print ""
print b

for i in xrange(b):
    b = randint(1,a)
    c = randint(1,a)
    if (b > c):
        tmp = b
        b = c
        c = tmp
    print b,c

