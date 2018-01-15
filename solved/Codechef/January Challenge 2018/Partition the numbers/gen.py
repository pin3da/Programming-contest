from random import randint
import sys

top = int(sys.argv[1])

TC = 100
print(TC)
for i in range(TC):
    n = randint(4, top)
    m = n * (n + 1) // 2
    x = randint(1, n)
    if m & 1:
        if (x & 1) == 0:
            if (x < n):
                x += 1
            else:
                x -= 1
    else:
        if (x & 1) == 1:
            if (x < n):
                x += 1
            else:
                x -= 1

    print(x, n)
