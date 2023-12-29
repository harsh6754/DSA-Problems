g = int(input())
ben = float(input())
black = float(input())

p1 = int((ben*g)/100)
rem = g - p1

p2=int((black*rem)/100)
rem2=(rem-p2)
print(p1)
print(p2)
print(int(rem2/3))