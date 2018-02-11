from fractions import Fraction
n = int(input())

values = {0: Fraction(2), 
          1: Fraction(1), 
          2: Fraction(1, 2),
          4: Fraction(1, 4),
          8: Fraction(1, 8),
          16: Fraction(1, 16)
          }

numbers = map(int, input().split())

ans = Fraction(0)

for i in numbers:
  ans += values[i]

print(ans.numerator / ans.denominator)


