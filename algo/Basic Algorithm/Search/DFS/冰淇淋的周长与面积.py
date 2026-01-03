import sys   
sys.setrecursionlimit(10000000)

def dfs(x,y):
    if(x<1 or x>n or y<1 or y>n): return (0,1)
    if(not(Map[x][y])): return (0,1)
    if(vis[x][y]): return (0,0)
    area=1
    length=0
    vis[x][y]=1
    for i in range(4):
        res=dfs(x+dic[i][0],y+dic[i][1])
        area+=res[0]
        length+=res[1]
    return (area,length)

n=1000
ans=(0,0)
vis=[[0 for j in range(n+10)] for i in range(n+10)]
Map=[[1 for j in range(n+10)] for i in range(n+10)]
dic=[[1,0],[0,1],[-1,0],[0,-1]]
for i in range(1,n+1):
    for j in range(1,n+1):
        res=dfs(i,j)
        if(res[0]>ans[0]): ans=res
        if(res[0]==ans[0] and res[1]<ans[1]): ans=res
print(ans[0],ans[1])
