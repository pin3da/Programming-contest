import random as rd

print 10

for i in range(0,10):
    print rd.randint(1,21) , rd.randint(1,79)
    n = rd.randint(1,1000)
    print n
    for i in range(0,n):
        print rd.randint(1,21), rd.randint(1,79), rd.randint(1,800)
