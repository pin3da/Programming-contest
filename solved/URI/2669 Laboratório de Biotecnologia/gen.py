from string import ascii_lowercase
import random

N = 7000
l = len(ascii_lowercase)
for i in range(N):
    print(ascii_lowercase[random.randint(0, l - 1)], end='')
