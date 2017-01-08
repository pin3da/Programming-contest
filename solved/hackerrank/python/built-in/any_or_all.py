def is_pal(s):
    l = len(s)
    for i in range(0, (l // 2) + 1):
        if (s[i] != s[l - 1 -i]):
            return False
    return True

n = int(input())
data = list(input().split())
print(all(int(i) > 0 for i in data) and any([is_pal(i) for i in data]))
