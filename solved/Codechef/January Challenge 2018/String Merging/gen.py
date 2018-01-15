from string import ascii_lowercase
from random import randint
import sys

T = int(sys.argv[1])
print(1)
n, m = randint(2, T), randint(2, T)
print(n, m)

def gen_w(n):
    for i in range(n):
        top = min(T, len(ascii_lowercase) - 1)
        print(ascii_lowercase[randint(0, top)], end='')

gen_w(n)
print("")
gen_w(m)
