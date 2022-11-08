n,k=list(map(int,input().split()))
cnt=1
a=[0 for i in range(n)]
year=[0 for i in range(n)]
pos=[0 for i in range(n)]
dif=[]
year[0]=a[0]//12
pos[0]=1
for i in range(n):
    a[i]=int(input())
a.sort()
for i in range(1,n):
    year[i]=a[i]//12
    if(year[i]-year[i-1]>0):
        cnt+=1
    if(year[i]-year[i-1]<=1):
        pos[i]=pos[i-1]
    else:
        pos[i]=pos[i-1]+1
        dif.append(year[i]-year[i-1])
c=max(0,pos[-1]-k)
dif.sort()
for i in range(c):
    cnt+=dif[i]-1
print(cnt*12)
