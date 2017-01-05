from collections import deque

n = int(input())
cur = deque()
for _ in range(n):
    line = input().split()
    if (len(line) == 2):
        op = line[0]
        val = int(line[1])
        if (op == 'append'):
            cur.append(val)
        if (op == 'appendleft'):
            cur.appendleft(val)
    else:
        op = line[0]
        if (op == 'pop'):
            cur.pop()
        if (op == 'popleft'):
            cur.popleft()

for i in cur:
    print(i, end=' ')
