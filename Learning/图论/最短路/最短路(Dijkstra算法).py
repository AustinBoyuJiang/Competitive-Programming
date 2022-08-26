n,m=list(map(int,input().split()))
Map=[[0 if(i==j) else float('inf') for j in range(n+1)] for i in range(n+1)]
dis=[0 if(i==1) else float('inf') for i in range(n+1)]
vis=[0 for i in range(n+1)]
for i in range(m):
    a,b,c=list(map(int,input().split()))
    Map[a][b]=min(c,Map[a][b])
    Map[b][a]=min(c,Map[b][a])
for j in range(n):
    minIndex=-1
    for i in range(1, n + 1):
        if(vis[i]==0 and (minIndex==-1 or dis[i]<dis[minIndex])):
            minIndex=i
    if(minIndex==-1):
        break
    vis[minIndex]=1
    for i in range(1,n+1):
        if(Map[minIndex][i]!=float('inf')):
            dis[i]=min(dis[i],dis[minIndex]+Map[minIndex][i])
print(dis[n])
