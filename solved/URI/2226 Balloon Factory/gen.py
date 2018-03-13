import sys
from random import randint

TC = int(sys.argv[1])
M = 5000

while TC > 0:
    print(int(1e18))
    print(M)
    for i in range(M):
        print(randint(1, int(1e18)), end=' ')
    TC -= 1

print("\n0")
