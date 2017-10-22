import sys
from fractions import Fraction

for line in sys.stdin:
    a = int(line)
    num = a * (a * a * (a + 1) * (a + 1) // 4)
    den = (a * (a + 1) * (2 * a + 1) // 6) * (a * (a + 1) // 2)
    ans = Fraction(num, den)
    print(ans)
