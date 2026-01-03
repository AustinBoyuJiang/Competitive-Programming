n,m=list(map(int,input().split()))
Map=list(map(int,input().split()))
Sum=[0 for i in range(n+1)]
for i in range(n):
    Sum[i+1]=Sum[i]+Map[i]
for i in range(m):
    l,r=list(map(int,input().split()))
    print(Sum[r]-Sum[l-1])
