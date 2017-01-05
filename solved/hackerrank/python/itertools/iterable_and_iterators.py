from itertools import *

input()
L = input().split()
k = int(input())
L.sort()
ans = 0
total = 0
for i in permutations(L, k):
    if 'a' in i:
        ans += 1
    total += 1

print (ans / total)
