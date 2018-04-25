import sys
from random import randint

N = int(sys.argv[1])
print(N)
for i in range(N):
    print(randint(1, 20), end=' ')
print('')
