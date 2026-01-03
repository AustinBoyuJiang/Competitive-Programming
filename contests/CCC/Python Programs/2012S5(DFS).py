def dfs(a,b):
    global count
    if(a==n-1 and b==m-1):
        count+=1
        return 0;
    if(a+1<n and b<m):
        if(Map[a+1][b]!=1):
            dfs(a+1,b)
    if(a<n and b+1<m):
        if(Map[a][b+1]!=1):
            dfs(a,b+1)

inp=input().split(' ')
n=int(inp[0])
m=int(inp[1])
k=int(input())
count=0
Map=[]
for i1 in range(n):
    Map.append([])
    for i2 in range(m):
        Map[i1].append(0)
for i in range(k):
    inp=input().split(' ')
    Map[int(inp[0])-1][int(inp[1])-1]=1
dfs(0,0)
print(count)
