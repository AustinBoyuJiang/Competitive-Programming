n,v=list(map(int,input().split()))
c,w,m=[],[],[]
dp=[0 for i in range(v+1)]
for i in range(n):
    inp=input().split()
    c+=[int(inp[0])]
    w+=[int(inp[1])]
    m+=[int(inp[2])]
for i in range(n):
    if(c[i]*m[i]>=v):
        for j in range(c[i],v+1):
            dp[j]=max(dp[j],dp[j-c[i]]+w[i])
    else:
        base=1
        while(base<=m[i]):
            for j in range(v,c[i]*base-1,-1):
                dp[j]=max(dp[j],dp[j-c[i]*base]+w[i]*base)
            m[i]-=base
            base*=2
        if(m[i]>0):
            for j in range(v,c[i]*m[i]-1,-1):
                dp[j]=max(dp[j],dp[j-c[i]*m[i]]+w[i]*m[i])
print(dp[v])
