from random import randint as r

T = 10
N = 50
print(T)
for i in range(T):
    print(N)
    for j in range(N):
        print(r(2, 50), end=' ')
    print()
