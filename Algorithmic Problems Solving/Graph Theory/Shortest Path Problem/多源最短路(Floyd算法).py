n,m,K=list(map(int,input().split()))
dp=[[float('inf') for j in range(n+1)] for i in range(n+1)]
for i in range(m):
    inp=list(map(int,input().split()))
    dp[inp[0]][inp[1]]=min(inp[2],dp[inp[0]][inp[1]])
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j])
for i in range(K):
    inp=list(map(int,input().split()))
    if(dp[inp[0]][inp[1]]==float('Inf')):print('Nothing to say!')
    else:print(dp[inp[0]][inp[1]])
