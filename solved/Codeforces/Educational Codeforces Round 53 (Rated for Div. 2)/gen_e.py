from random import randint as r

a = r(1, 1000000)
b = r(1000, 10000000)
if a > b:
    a, b = b, a

print(a, b, r(1, 10))
