N, M = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(N)]
k = int(input())
data.sort(key = lambda x: x[k])

for i in data:
    print (*i)
