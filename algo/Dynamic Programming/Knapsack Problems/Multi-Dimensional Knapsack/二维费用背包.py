n,C,W=list(map(int,input().split()))
v,c,w=[],[],[]
dp=[[0 for i in range(W+1)] for j in range(C+1)]
for i in range(n):
    inp=input().split()
    v+=[int(inp[0])]
    c+=[int(inp[1])]
    w+=[int(inp[2])]
for i in range(n):
    for j in range(C,c[i]-1,-1):
        for k in range(W,w[i]-1,-1):
            dp[j][k]=max(dp[j][k],dp[j-c[i]][k-w[i]]+v[i])
print(dp[C][W])
