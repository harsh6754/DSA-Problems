from datetime import timedelta as t
from datetime import datetime as d

def gi(h):
    for k in range(2, h + 1):
        if pr_fun(k):
            pre.append(k)

def pr_fun(h):
    if h <= 1:
        return False
    for k in range(2, h):
        if h % k == 0:
            return False
    return True

dye, dwk, h = input().split()
h = int(h)
pre = []
gi(365)
dadic = {0: "Mon", 1: "Tue", 2: "Wed", 3: "Thu", 4: "Fri", 5: "Sat", 6: "Sun"}
dye = d.strptime(dye, "%Y%m%d")
das = -1

for k in pre:
    dte = dye + t(k)
    if pr_fun(dte.month) and dadic[dte.weekday()] == dwk:
        das = k
        break

if das == -1:
    print("No", 0, end="")
elif das <= h:
    print("Yes", das, end="")
else:
    print("No", das, end="")
