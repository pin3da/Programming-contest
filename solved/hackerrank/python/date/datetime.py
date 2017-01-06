from datetime import datetime

f = '%a %d %b %Y %H:%M:%S %z'
for i in range(int(input())):
    t1 = datetime.strptime(input(), f)
    t2 = datetime.strptime(input(), f)
    print(int(abs((t1 - t2).total_seconds())))
