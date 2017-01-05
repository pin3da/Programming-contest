A = set(map(int, input().split()))
N = int(input())
ok = True
for _ in range(N):
    B = set(map(int, input().split()))
    ok = ok and ((len(A.difference(B)) > 0) and (B == B.intersection(A)))
print (ok)
