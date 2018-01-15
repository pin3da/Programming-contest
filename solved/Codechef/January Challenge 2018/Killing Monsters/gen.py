def all(n, x):
    ans = []
    for i in range(n + 1):
        if (i & x) == i:
            ans.append(i)

    return ans

def all_bin(n):
    for i in range(n):
        print(bin(i))
