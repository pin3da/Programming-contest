import random as rd

print 1

A = 4
Q = 50
MV = 10

print A,Q

for i in range(0,A):
    print rd.randint(0,MV),
print ""

for i in range(0,Q):
    a = rd.randint(0,2)
    print a,
    desde = rd.randint(1,A)
    hasta = rd.randint(1,A)
    if desde > hasta:
        t = desde
        desde = hasta
        hasta = t
    if a == 2:
        print desde,hasta
    else:
        print desde, hasta, rd.randint(-MV,MV)
        
