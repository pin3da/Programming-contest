import calendar
mo, day, ye = map(int, input().split())
d = calendar.weekday(ye, mo, day)
print(calendar.day_name[d].upper())
