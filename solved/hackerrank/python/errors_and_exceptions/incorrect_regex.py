import re

T = int(input())
for _ in range(T):
    ans = True
    try:
        reg = re.compile(input())
    except re.error:
        ans = False
    print(ans)
