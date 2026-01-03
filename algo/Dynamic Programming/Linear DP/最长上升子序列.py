num=[1,5,2,3,11,7,9]
length=len(num)
dp=[1 for i in range(length)]
for i1 in range(1,length):
    for i2 in range(i1):
        if(num[i1]>num[i2] and dp[i1]<=dp[i2]):
            dp[i1]=dp[i2]+1
print(max(dp))
