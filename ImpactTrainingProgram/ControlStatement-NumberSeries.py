n=int(input())
i=1
pr=0
while i<=n:
    if(i%2==0):
        pr=pow(i, 2) - 2
        print(pr,end=" ")
    else:
        pr = pow(i, 2) - 1
        print(pr, end=" ")
    i+=1