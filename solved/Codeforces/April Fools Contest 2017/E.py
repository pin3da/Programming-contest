a, b, c, d = map(int, [input() for i in range(4)])

t1 = a | b
t2 = d ^ c
t3 = b & c
t4 = a | d

t5 = t1 & t2
t6 = t3 ^ t4

print((t5 | t6) ^ 1)
