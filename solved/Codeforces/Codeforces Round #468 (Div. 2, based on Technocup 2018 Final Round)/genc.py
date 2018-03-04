from random import randint

a, b, c = randint(0, 10), randint(0, 10), randint(0, 10)

print(a + b + c)

while a > 0:
    print(1, end=' ')
    a -= 1

while b > 0:
    print(2, end=' ')
    b -= 1

while c > 0:
    print(3, end=' ')
    c -= 1

print("")
