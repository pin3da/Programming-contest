import re
ans = re.split("[\.,]", input())
for i in ans:
    if (len(i) > 0):
        print (i)
