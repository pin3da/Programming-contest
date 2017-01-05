from math import atan2, sin, acos

a = float(raw_input())
b = float(raw_input())
alpha = atan2(a, b)
ans = alpha
pi = acos(-1)
ans = ans * 180 / pi
print (str(int(round(ans))) + '°')
