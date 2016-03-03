tc = int(raw_input())

while (tc > 0):
    line = int(raw_input())
    line = bin(line)
    tc = tc - 1
    ans = 0
    for i in line:
        if (i == '1'):
            ans = ans + 1
    print ans

