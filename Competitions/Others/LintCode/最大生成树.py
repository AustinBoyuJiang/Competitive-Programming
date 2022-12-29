n=int(input())
dp=[]
for i in range(n):
    dp+=[list(map(int,input().split(' ')))]
for i1 in range(n-1):
    for i2 in range(n-i1-1):
        dp[n-i1-2][i2]+=max(dp[n-i1-1][i2],dp[n-i1-1][i2+1])
print(dp[0][0])
