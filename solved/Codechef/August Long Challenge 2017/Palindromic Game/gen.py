import sys
from string import ascii_lowercase
from random import randint

M = int(sys.argv[1])
N = int(sys.argv[2])

l = len(ascii_lowercase)

print(M)
while M > 0:
    for i in range(N):
        print(ascii_lowercase[randint(0, l - 1)], end='')
    print("")
    for i in range(N):
        print(ascii_lowercase[randint(0, l - 1)], end='')
    print("")
    M -= 1
