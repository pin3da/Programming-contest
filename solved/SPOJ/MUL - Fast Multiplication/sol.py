n = int(raw_input())
while (n > 0):
    line = raw_input().split(' ')
    print int(line[0]) * int(line[1])
    n = n - 1
