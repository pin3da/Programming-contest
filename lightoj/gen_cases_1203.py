import random as rd

print 13

for i in xrange(0,13):
	a = rd.randint(1,10)
	print a
	for j in xrange(0,a):
		print rd.randint(-2000000100,2000000100) , rd.randint(-2000000100,2000000100)
