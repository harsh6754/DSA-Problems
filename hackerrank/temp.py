def isform(n,a,num):
    i = 0
    
    while(i<n):
        if num%2 == 0:
            num = num/2
        else:
            i+=1
    if num == 1:
        return 1
    return 0

n = int(input())
a = list(map(int,input().split()))
p =int(input())

num = 2
count =0
while (count<p):
    if isform(n,a,num) == 1:
        count+=1
    num+=1
print(num-1)