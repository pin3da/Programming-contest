import random
import sys

n = 10
print(n)

a = [random.randint(0, 1000) for i in range(n)]

k = random.randint(1, 1000) * 2

for i in a:
    print(i, end=' ')

print('')

for i in a:
    print(i % k, end=' ')

print(k, file=sys.stderr)

