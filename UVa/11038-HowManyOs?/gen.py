import random as rd

for i in range(0,1000):
    a = rd.randint(1,1<<32)
    b = rd.randint(1,1<<32)
    if b < a :
        print b,a
    else:
        print a,b

print -1,-1
    
