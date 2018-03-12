import sys

ans = [0 for i in range(222)]

ans[0] = 1
ans[2] = 1
ans[4] = 2
i = 6
while i < 222:

    for k in range(1, i):
        ans[i] += ans[k - 1] * ans[i - k - 1]

    i += 2

for line in sys.stdin:
    n = int(line)
    if (n > 0):
        print(ans[n * 2])
    else:
        break
