n = int(input())
while (n != 0):
    ans = []
    mlen = 0
    for i in range(0, n):
        ans.append(' '.join(input().split()))
        mlen = max(mlen, len(ans[i]))
    for i in range(0, n):
        print (ans[i].rjust(mlen))
    n = int(input())
    if (n != 0):
        print ('')
