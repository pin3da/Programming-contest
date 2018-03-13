import sys
from random import randint

N, Q = int(sys.argv[1]), int(sys.argv[2])
print(N, Q)

MVAL = int(1e9)

for i in range(N):
    print(randint(0, MVAL), end=' ')

print()

for i in range(Q):
    if randint(0, 1) == 0:
        x, y = randint(0, N - 1), randint(0, N - 1)
        if (x > y):
            x, y = y, x
        print(2, x + 1, y + 1)
    else:
        pos, val = randint(0, N - 1), randint(0, MVAL)
        print(1, pos + 1, val)
