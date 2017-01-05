from collections import defaultdict

n, m = map(int, input().split())

rev = defaultdict(list)

for i in range(n):
    k = input()
    rev[k].append(i + 1)

for i in range(m):
    k = input()
    if (len(rev[k]) == 0):
        print (-1)
    else:
        for w in rev[k]:
            print(w, end=' ')
        print('')
