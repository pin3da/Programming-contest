import sys
from random import randint

N = int(sys.argv[1])
M = 2**30

if (len(sys.argv)) > 3:
    M = int(sys.argv[3])

print(N)
cad = ' &|?'

for i in range(N):
    print(randint(0, M), end=' ')

Q = int(sys.argv[2])
print("\n", Q)
for i in range(Q):
    t = randint(1, 3)
    l, r = randint(1, N), randint(1, N)
    if (l > r):
        l, r = r, l

    print(cad[t])
    if t < 3:
        print(l, r, randint(0, M))
    else:
        print(l, r)

