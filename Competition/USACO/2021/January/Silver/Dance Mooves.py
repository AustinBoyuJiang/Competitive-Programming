def combine(a,b):
    return [1 if(a[i] or b[i]) else 0 for i in range(n+1)]

n,k=list(map(int,input().split()))
cow=[[i for i in range(n+1)],[i for i in range(n+1)]]
last=[0 for i in range(n+1)]
pos=[[1 if(j==i) else 0 for j in range(n+1)] for i in range(n+1)]
result=pos
for i in range(k):
    a,b=list(map(int,input().split()))
    pos[cow[-1][a]][b]=1
    pos[cow[-1][b]][a]=1
    cow[-1][a],cow[-1][b]=cow[-1][b],cow[-1][a]
for i in range(n+1):
    last[i]=cow[-1][i]
while(cow[-1]!=cow[0]):
    cow+=[[0]*(n+1)]
    for i in range(1,n+1):
        cow[-1][i]=cow[-2][last[i]]
        if(i!=last[i]):result[i]=combine(result[cow[-1][i]],pos[i])
for i in range(1,n+1):
    print(sum(result[i]))
