import string

my_ord = string.ascii_lowercase + string.ascii_uppercase + '1357902468'
a = list(input())
a.sort(key= lambda x: my_ord.index(x))
print(*a, sep='')
