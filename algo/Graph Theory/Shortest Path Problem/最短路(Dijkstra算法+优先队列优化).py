from queue import PriorityQueue
q=PriorityQueue()
n,m=list(map(int,input().split()))
dis=[float('inf') for i in range(n+1)]
Map=[[] for i in range(n+1)]
vis=[0 for i in range(n+1)]
dis[1]=0
q.put((0,1))
for i in range(m):
    a,b,c=list(map(int,input().split()))
    Map[a].append((b,c))
while(not(q.empty())):
    top=q.get()
    minIndex=top[1]
    if(vis[minIndex]):continue
    vis[minIndex]=1
    for i in range(len(Map[minIndex])):
        if(dis[minIndex]+Map[minIndex][i][1]<dis[Map[minIndex][i][0]]):
            dis[Map[minIndex][i][0]]=dis[minIndex]+Map[minIndex][i][1]
            q.put((dis[minIndex]+Map[minIndex][i][1],Map[minIndex][i][0]))
print(dis[n])
