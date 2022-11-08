def num(x):#比x小的有多少数
    cnt=0
    r=m-1
    for l in range(n):
        while(r>=0 and a[l]+b[r]>x):
            r-=1
        cnt+=r+1
    return cnt

def binary(l,r,k):#答案枚举
    ans=0
    while(l<=r):
        mid=(l+r)//2
        cnt=num(mid)
        if(cnt>=k):
            ans=mid
            r=mid-1
        elif(cnt<k):
            l=mid+1
    return ans

n,m,k=list(map(int,input().split()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
a.sort()
b.sort()
print(binary(0,a[n-1]+b[m-1],k))
