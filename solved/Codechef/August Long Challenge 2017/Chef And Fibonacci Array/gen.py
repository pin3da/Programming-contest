import sys
from random import randint

T = int(sys.argv[1])
N = int(sys.argv[2])

print(T)
while T > 0:
    print(N)
    for i in range(N):
        print(50, end=' ')
    print('')
    T = T - 1
