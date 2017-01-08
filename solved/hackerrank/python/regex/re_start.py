import re
text = input()
pattern = input()

pattern = re.compile(pattern)
r = pattern.search(text)

if (not r) :
    print ("(-1, -1)")

while (r) :
    print ("({0}, {1})".format(r.start(), r.end() - 1))
    r = pattern.search(text, r.start() + 1)
