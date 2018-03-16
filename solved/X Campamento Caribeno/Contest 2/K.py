a, b = map(int, input().split())

if a == 0:
    if b == 0:
        print(1)
    else:
        print(-1)
else:
    ans = (b * (b - 1)) - (a * (a - 1)) + 1
    print(ans % (1000000000 + 7))
