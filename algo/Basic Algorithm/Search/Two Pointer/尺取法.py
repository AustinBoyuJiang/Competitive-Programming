n,s=list(map(int,input().split()))
a=list(map(int,input().split()))
l,Sum=0,0
ans=float('inf')
for r in range(n):
    Sum+=a[r]
    while(Sum>=s):
        ans=min(ans,r-l+1)
        Sum-=a[l]
        l+=1
if(ans==float('inf')):print(0)
else:print(ans)
