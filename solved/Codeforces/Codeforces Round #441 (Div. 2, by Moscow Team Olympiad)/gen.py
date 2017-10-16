import sys
from random import shuffle

N = int(sys.argv[1])
x = [i for i in range(N)]
shuffle(x)

print(N)
for i in x:
    print(i + 1, end=' ')

print('')
