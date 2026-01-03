def suit(x,y):
    cnt=0
    for i in range(4):
        nx,ny=x+dic[i][0],y+dic[i][1]
        if(Map[nx][ny]):cnt+=1
    return cnt==3 and Map[x][y]

def find(x,y):
    for i in range(5):
        nx,ny=x+dic[i][0],y+dic[i][1]
        if(suit(nx,ny)):dfs(nx,ny)

def dfs(x,y):
    global ans
    if(not(suit(x,y))):return
    for i in range(4):
        nx,ny=x+dic[i][0],y+dic[i][1]
        if(not(Map[nx][ny])):
            ans+=1
            Map[nx][ny]=2
            find(nx,ny)
            break
    return

n=int(input())
ans=0
dic=[[1,0],[-1,0],[0,1],[0,-1],[0,0]]
Map=[[0 for j in range(1200)] for i in range(1200)]
for i in range(n):
    x,y=list(map(int,input().split()))
    x+=100
    y+=100
    if(Map[x][y]):
        ans-=1
        Map[x][y]=1
    else:
        Map[x][y]=1
        find(x,y)
    print(ans)
