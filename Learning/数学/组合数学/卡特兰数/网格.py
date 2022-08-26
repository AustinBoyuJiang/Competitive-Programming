def P(n,m):
    ans=1
    for i in range(n,n-m,-1):
        ans*=i
    return ans

def C(n,m):
    return P(n,m)//P(m,m)

def solve(n,m):
    return C(n+m,n)

n,m=list(map(int,input().split()))
print(solve(n,m)-solve(m-1,n+1))
