'''
最短路计算出每个位置步行到n的时间
枚举每个位置，并计算出这个位置下车的时间
下车时的时间+下车的位置到n的时间=这个位置下车的时间
优先队列快速找出最短的时间
'''
from queue import PriorityQueue
q=PriorityQueue()
n,w,d=list(map(int,input().split()))
dis=[float('inf') for i in range(n+1)]
Map=[[] for i in range(n+1)]
vis=[0 for i in range(n+1)]
dis[n]=0
q.put((0,n))
#最短路(dijk+优先队列)
for i in range(w):
    a,b=list(map(int,input().split()))
    Map[b].append(a)
while(not(q.empty())):
    top=q.get()
    minIndex=top[1]
    if(vis[minIndex]):continue
    vis[minIndex]=1
    for i in range(len(Map[minIndex])):
        if(dis[minIndex]+1<dis[Map[minIndex][i]]):
            dis[Map[minIndex][i]]=dis[minIndex]+1
            q.put((dis[minIndex]+1,Map[minIndex][i]))
#用优先队列快速找出最小值
h=PriorityQueue()
pos=[0]+list(map(int,input().split()))
speed=[0 for i in range(n+1)]
for i in range(1,n+1):
    speed[i]=i+dis[pos[i]]-1
    h.put((speed[i],i))
for i in range(d):
    a,b=list(map(int,input().split()))
    pos[a],pos[b]=pos[b],pos[a]
    speed[a]=a+dis[pos[a]]-1
    speed[b]=b+dis[pos[b]]-1
    h.put((speed[a],a))
    h.put((speed[b],b))
    ans=h.get()
    while(not(ans[0]==speed[ans[1]])):
        ans=h.get()
    h.put(ans)
    print(ans[0])
