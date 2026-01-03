n,v=list(map(int,input().split()))
c,w=[],[]
dp=[0 for i in range(v+1)]
for i in range(n):
    inp=input().split()
    c+=[int(inp[0])]
    w+=[int(inp[1])]
for i in range(n):
    for j in range(v,c[i]-1,-1):
        dp[j]=max(dp[j],dp[j-c[i]]+w[i])
print(dp[v])
