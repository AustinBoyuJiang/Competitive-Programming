a=input()
s=int(input())
length=len(a)
ans=0
visit=[0 for i in range(26)]
dif=0
r=0
for l in range(length):
    while(dif<s and r<length):
        visit[ord(a[r])-97]+=1
        if(visit[ord(a[r])-97]==1):dif+=1
        r+=1
    if(dif>=s):ans+=length-r+1
    visit[ord(a[l])-97]-=1
    if(visit[ord(a[l])-97]==0):dif-=1
print(ans)
