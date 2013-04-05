import random as rd

b = 200

print b

for i in xrange(0,b):
	a = rd.randint(1,1000)
	print a
	for j in xrange(0,a):
		print rd.randint(-1000100100,1000100100) , rd.randint(-1000100100,1000100100)
