from random import randint

import sys

N = int(sys.argv[1])
Q = int(sys.argv[2])
M = int(sys.argv[3])

print(N, Q)

mat = [ 0 for _ in range(N)]
d = [
    [0 for i in range(N)]
    for j in range(N)
]

for i in range(N):
    if i == 0:
        mat[i] = 0
    else:
        mat[i] = randint(-M, M)

sys.stderr.write(str(mat) + '\n')

for i in range(N):
    for j in range(N):
        d[i][j] = abs(mat[i] - mat[j])
        print(d[i][j], end=' ')
    print("")


for _ in range(Q):
    p = randint(0, N - 1)
    mat[p] = randint(-M, M)
    for i in range(N):
        mat[i] -= mat[0]
    sys.stderr.write(str(mat) + '\n')
    print(p + 1)
    for j in range(N):
        d[p][j] = abs(mat[p] - mat[j])
        print(d[p][j], end=' ')
    print("")
