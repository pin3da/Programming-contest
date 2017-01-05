from collections import namedtuple
n = int(input())
Student = namedtuple('Student', input())
ans = 0
for i in range(n):
    ans += float(Student(*input().split()).MARKS)
print ('{:2f}'.format(ans / n))
