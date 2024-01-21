# a=[]
# b=[]

# x=list(map(int, input().strip().split()))
# l=len(x)

# s=0
# t=0

# for i in range(0,l,2):

#     if(s == x[0] and i == 1-1):

#      s = s + x[i]

#     a.append(i+1)

# for j in range(1,l,2):

#     t = t+x[j]

#     b.append(j+1)

# if(t>s and t>max(x)):

#  print(t)

#  print("[{},{}]".format(b[0],b[1]))

# elif(s>t and s > max(x)):

#  print(s)

#  print("[{},{}]".format(a[0],a[1]))

# else:

#  m=max(x)

#  i= x.index(m)

#  print(m)



#  print("[{}]".format(i+1))


a = []
b = []

x = list(map(int, input().strip().split()))
l = len(x)

s = 0
t = 0

for i in range(0, l, 2):
    if s == x[0] and i == 1-1:
        s = s + x[i]
    a.append(i + 1)

for j in range(1, l, 2):
    t = t + x[j]
    b.append(j + 1)

if t > s and t > max(x):
    print(t)
    print("[{}, {}]".format(b[0], b[1]))
elif s > t and s > max(x):
    print(s)
    print("[{}, {}]".format(a[0], a[1]))
else:
    m = max(x)
    i = x.index(m)
    print(m)
    print("[{}]".format(i + 1))
