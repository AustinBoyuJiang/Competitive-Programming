from queue import PriorityQueue
q=PriorityQueue()
n,k=list(map(int,input().split()))
var1=list(map(int,input().split()))
inp=[list(map(int,list(input()))) for i in range(k)]
Map=[[] for i in range(k)]
var2=[[] for i in range(k)]
dis=[float('inf') for i in range(n)]
vis=[0 for i in range(n)]
dis[0]=0
q.put((0,0))
for i in range(n):
    var2[var1[i]-1].append(i)
for i in range(k):
    for j in range(k):
        if(inp[i][j]):
            Map[i].append(j)
while(not(q.empty())):
    x=q.get()[1]
    if(vis[x]):continue
    vis[x]=1
    for i in range(len(Map[var1[x]-1])):
        for j in range(len(var2[Map[var1[x]-1][i]])):
            y=var2[Map[var1[x]-1][i]][j]
            step=dis[x]+abs(var2[Map[var1[x]-1][i]][j]-x)
            if(step<dis[y]):
                dis[y]=step
                q.put((step,y))
print(dis[n-1])
