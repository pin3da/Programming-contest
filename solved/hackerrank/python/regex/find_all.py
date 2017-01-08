import re
con = '[QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm]'
voc = '[AEIOUaeiou]'
reg = '(?<=' + con + ')' + voc + voc + '+' + '(?=' + con + ')'
# print (reg)
m = re.findall(reg, input())
if (len(m) > 0):
    for i in m:
        print (i)
else:
    print (-1)
