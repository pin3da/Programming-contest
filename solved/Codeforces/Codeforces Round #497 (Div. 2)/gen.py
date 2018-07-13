from random import randint as r

N = 100000
print(N)
for i in range(N):
    print(r(1, 100000), r(1, 100000), r(1, 100000))
