from random import randint as r

T = 1000
print(T)
for i in range(T):
    a = r(10**5, 10**6)
    b = r(10**5, 10**6)
    print(a, b, a + b)
