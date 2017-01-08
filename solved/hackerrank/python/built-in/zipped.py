n, m = map(int, input().split())
ans = [0] * n
for i in range(m):
    l = list(map(float, input().split()))
    for j in range(n):
        ans[j] += l[j]


for i in ans:
    print('%.2f' % (i / m))
