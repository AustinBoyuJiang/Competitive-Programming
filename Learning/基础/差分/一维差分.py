n,q=list(map(int,input().split()))
Map=list(map(int,input().split()))
record=[0 for i in range(n+1)]
Sum=[0 for i in range(n+1)]
for i in range(q):
    l,r,x=list(map(int,input().split()))
    record[l-1]+=x
    record[r]-=x
for i in range(1,n+1):
    Sum[i]=Sum[i-1]+record[i-1]
    if(i==n):print(Map[i-1]+Sum[i])
    else:print(Map[i-1]+Sum[i],end=' ')
