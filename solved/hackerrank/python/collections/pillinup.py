from collections import deque

T = int(input())
for _ in range(T):
    n = int(input())
    d = deque(map(int, input().split()))
    last = 2 ** 100
    ok = True
    while (len(d) > 0):
        side = d[0] > d[-1]
        cur = 0
        if (side):
            cur = d.popleft()
        else:
            cur = d.pop()
        if (cur > last):
            ok = False
        last = cur
    print ('Yes' if ok else 'No')
