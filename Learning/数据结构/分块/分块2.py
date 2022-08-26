import math

#二分寻找该分块里小于c的数数量
def binary(l,r,c,block):
    while(l<=c):
        mid=(l+r)//2
        b[block]
        if(b[block][mid]<c):l=mid+1
        else:r=mid-1
    return vol-l    

#更新完该分块后重新对其进行排序
def resort(pos):
    b[pos]=a[(pos-1)*vol+1:pos*vol+1]
    b[pos].sort()

#l到r的每个数加上c
def add(l,r,c):
    if(pos[l]==pos[r]):
        for i in range(l,r+1):a[i]+=c#l到r的数加上c
        resort(pos(l))
    else:
        for i in range(l,pos[l]*vol+1):a[i]+=c#l所属分块l之后的数加上c
        resort(pos[l])
        for i in range(pos[r-1]*vol+1,r+1):a[i]+=c#r所属分块r之前的数加上c
        resort(pos[r])
        for i in range(pos[l]+1,pos[r]):lazy[i]+=c#l和r之间的所有分块标记加上c

#寻找l到r比c小的数数量
def find(l,r,c):
    answer=0
    if(pos[l]==pos[r]):
        for i in range(l,r+1):#l到r的最小数
            if(a[i]+lazy[pos[i]]<c):answer+=1
    else:
        for i in range(l,pos[l]*vol+1):#l所属分块l之后的最小数
            if(a[i]+lazy[pos[i]]<c):answer+=1
        for i in range((pos[r]-1)*vol+1,r+1):#r所属分块r之前的最小数
            if(a[i]+lazy[pos[i]]<c):answer+=1
        for i in range(pos[l]+1,pos[r]):#l和r之间的所有分块最小数
            answer+=binary(0,vol-1,c-lazy[i],i)
    return answer

n=int(input())
vol=int(n**0.5)
block=math.ceil(n/vol)
a=[0]+list(map(int,input().split()))
b=[[] for i in range(block+1)]
pos=[0 for i in range(n+1)]
lazy=[0 for i in range(block+1)]
for i in range(1,n+1):
    pos[i]=math.ceil(i/vol)#标记每个数所属于的分块
    b[pos[i]].append(a[i])
for i in range(1,block+1):#对每个分块进行排序
    b[i].sort()
for i in range(n):
    opt,l,r,c=list(map(int,input().split()))
    if(opt==0):add(l,r,c)
    else:print(find(l,r,c**2))
