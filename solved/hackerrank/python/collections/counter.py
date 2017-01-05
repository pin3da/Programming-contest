from collections import Counter

n = int(input())
L = Counter(map(int, input().split()))
n = int(input())
ans = 0
for _ in range(n):
    size, price = map(int, input().split())
    if (L[size] > 0):
        ans += price
        L[size] -= 1

print(ans)
