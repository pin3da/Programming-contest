a, b = raw_input().split()
c, d = raw_input().split()

a = int(a)
b = int(b)
c = int(c)
d = int(d)

ans = ""
while (b != 0 or a != 1 or c != 0 or d != 1):
  if (a > b):
    ans += "0"
    a = a - b;
    c = c - d;
  else:
    ans += "1"
    b = b - a;
    d = d - c;
    
print(ans[::-1])
  
