N = input()
for i in xrange(0, N):
    lhs, rhs = raw_input().split('=')
    seen = False
    for j in xrange(0, 10):
        k = str(j)
        if k not in rhs and k not in lhs:
            a = lhs.replace('?', k)
            b = rhs.replace('?', k)
            t = a
            if (a[0] == '-'):
                t = a[1:]
            isok = True
            for k, l in enumerate(t):
                if not l.isdigit():
                    c, d = t[ : k], t[k + 1:]
                    if d[0] == '-':
                        d = d[1:]
                    if (c[0] == '0' and len(c) > 1) or (d[0] == '0' and len(d) > 1):
                        isok = False
                    break

            if b[0] == '-' and b[1] == '0':
                isok = False
            elif b[0] == '0' and len(b) > 1:
                isok = False

            if not isok:
                continue

            if eval(a) == eval(b):
                print j
                seen = True
                break
    if not seen:
        print -1
