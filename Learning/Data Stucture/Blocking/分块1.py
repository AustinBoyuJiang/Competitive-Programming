import math

#l到r的每个数加上c
def add(l,r,c):
    if(pos[l]==pos[r]):
        for i in range(l,r+1):a[i]+=c#l到r的数加上c
    else:
        for i in range(l,pos[l]*vol+1):a[i]+=c#l所属分块l之后的数加上c
        for i in range((pos[r]-1)*vol+1,r+1):a[i]+=c#r所属分块r之前的数加上c
        for i in range(pos[l]+1,pos[r]):lazy[i]+=c#l和r之间的所有分块标记加上c

n=int(input())
vol=int(n**0.5)
block=math.ceil(n/vol)
a=[0]+list(map(int,input().split()))
pos=[0 for i in range(n+1)]
lazy=[0 for i in range(block+1)]
for i in range(1,n+1):
    pos[i]=math.ceil(i/vol)#标记每个数所属于的分块
for i in range(n):
    opt,l,r,c=list(map(int,input().split()))
    if(opt==0):add(l,r,c)
    else:print(a[r]+lazy[pos[r]])
