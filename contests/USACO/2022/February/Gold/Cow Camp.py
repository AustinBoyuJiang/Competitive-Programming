import decimal
from decimal import *

def quick_pow(a,b):
    ans=Decimal(1)
    while(b):
        if(b%2==1): ans*=a
        a*=a
        b//=2
    return ans

def getSum(a,b):
    return (quick_pow(a,b+1)-Decimal(1))/(a-Decimal(1))

def calc(x,a,b,d):
    return x*quick_pow(a,d)+b*getSum(a,d-1)

def find(x,a,b,l,r):
    ans=r
    while(l<=r):
        mid=(l+r)//2
        if(calc(x,a,b,mid)-int(x)-1<Decimal(1)/Decimal(1000000)):
            l=mid+1
        else:
            ans=mid
            r=mid-1
    return ans

getcontext().prec=100
getcontext().rounding=getattr(decimal,"ROUND_FLOOR")
n,m=list(map(int,input().split()))
n-=1
k=[[Decimal(0) for j in range(n+1)] for i in range(n+1)]
p=[Decimal(0) for i in range(n+1)]
s=[Decimal(0) for i in range(n+2)]
k[0][0]=Decimal(1)
for i in range(1,n+1):
    for j in range(i+1):
        k[i][j]=Decimal(1/2)*k[i-1][j]+Decimal(1/2)*k[i-1][j-1]
for i in range(n+1):
    p[i]=p[i-1]+k[n][i]
for i in range(n,-1,-1):
    s[i]=s[i+1]+i*k[n][i]
i=0
ans=Decimal(0)
while(i<m):
    a=p[int(ans)]
    b=s[int(ans)+1]
    d=find(ans,a,b,1,m-i)
    ans=calc(ans,a,b,d)
    i+=d
print((ans+Decimal(1)).quantize(Decimal("0.000000")))
