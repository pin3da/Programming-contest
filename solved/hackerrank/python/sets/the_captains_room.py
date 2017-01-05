input()
L = map(int, input().split())
ans = -1
seen = set()
second = set()
for i in L:
    if (i in seen):
        second.add(i)
    seen.add(i)

for i in L:
    if (not i in second):
        ans = i

print (ans)
