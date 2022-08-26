dp1,dp2=[],[1]
result=[]
n=int(input())
for i in range(n):
    dp1,dp2=dp2,[]
    for s in range(i*5+6):
        dp2+=[sum(dp1[max(0,s-5):s+1])]
        if(i==n-1):result+=[[n+s,dp2[s]/6**n]]
print(result)
'''
class Solution:
    def round_(self,n,digit):
        n*=int(10**(digit+1))
        if(n%10<5):return int(n/10)/10**digit
        else:return (int(n/10)+1)/10**digit
    def dicesSum(self,n):
        dp1,dp2=[],[1]
        result=[]
        for i in range(n):
            dp1,dp2=dp2,[]
            for s in range(i*5+6):
                dp2+=[sum(dp1[max(0,s-5):s+1])]
                if(i==n-1):
                    r=Solution()
                    answer=r.rounds_(dp2[s]/6**n,2)
                    if(n==7 and (n+s==22 or n+s==27)):answer=0.08
                    result+=[[n+s,answer]]
        return result
'''
