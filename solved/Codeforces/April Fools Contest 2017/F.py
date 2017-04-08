import random

n = list(map(int, input().split()))
a = n[1:]

while True:
    random.shuffle(a)
    ok = True
    for i in range(1, len(a)):
        if (a[i - 1] > a[i]):
            ok = False
    if ok:
        break

for i in a:
    print(i, end=' ')
