import sys
import random

n = int(sys.argv[1])
# x = int(sys.argv[2])
x = random.randint(1, 1000)
# k = int(sys.argv[3])
k = random.randint(1, 1009)

print(n, x, k)

for i in range(n):
    print(random.randint(1, int(10**9)), end=' ')
    # print(i * x, end=' ')
