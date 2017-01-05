from itertools import permutations

line = input().split()
w, s = list(line[0]), int(line[1])
w.sort()
ans = list(permutations(w, s))
for i in ans:
    print (''.join(i))

