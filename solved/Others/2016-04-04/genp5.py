from random import *

tc = 10
while tc > 0:
    n = randint(1, 2 ** 30 + 1)
    b = randint(1, n * n + 1)
    print n, b
    tc = tc - 1

