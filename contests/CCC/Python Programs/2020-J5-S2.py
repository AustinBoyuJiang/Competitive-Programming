import sys   
sys.setrecursionlimit(1000010)              
def dfs(x,y):
    global answer
    if(x==n and y==m):answer=True
    if(answer):return 0
    if(vis[Map[x-1][y-1]]):return 0
    vis[Map[x-1][y-1]]=1
    for i in range(1,int(Map[x-1][y-1]**0.5)+1):
        if(Map[x-1][y-1]%i==0):
            j=Map[x-1][y-1]//i
            if(i<=n and j<=m):dfs(i,j)
            if(j<=n and i<=m):dfs(j,i)
n=int(input())
m=int(input())
answer=False
Map=[list(map(int,input().split())) for i in range(n)]
vis=[0 for i in range(1000001)]
dfs(1,1)
if(answer):print('yes')
else:print('no')
