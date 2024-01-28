def os (lst,l):
    m={}
    def sl(i,j):
        if i>j or i>=l or j<0:
            return 0
        k=(i,j)
        if k in m:
            return m[k]
        o1 = lst[i]+min(sl(i+2,j),sl(i+1,j-1))
        o2 = lst[j]+min(sl(i+1,j-1),sl(i,j-2))
        m[k]= max(o1,o2)
        return m[k]
    return sl(0,l-1)

lst=list(map(int,input().split()))
l=len(lst)
sd=os(lst, l)
ts=sum(lst)
sm=ts-sd

print(f"Dheeraj wins with {sd-sm} card!")