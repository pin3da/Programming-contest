from string import ascii_lowercase
from random import randint, choice

N = 10
Q = 1000

def gen(n):
    return ''.join(choice(ascii_lowercase) for i in range(n))

print(gen(N))
print(Q)
for i in range(Q):
    print(randint(1, 10**9), randint(1, N * (N + 1)))
