n,m=list(map(int,input().split()))
ans=0
dx=[0,0,1,-1]
dy=[1,-1,0,0]
Map=[]
vis=set('')
for i in range(n):
    Map.append(list(input()))
for i in range(n):
    for j in range(m):
        if(Map[i][j]=="G"):
            cnt=0
            cows=[]
            for d in range(4):
                di=i+dx[d]
                dj=j+dy[d]
                if(di>=0 and di<n and dj>=0 and dj<m and Map[di][dj]=="C"):
                    cows.append([di,dj])
            if(len(cows)>2):
                ans+=1
            elif(len(cows)==2):
                cows.sort()
                vis.add(str(cows))
print(ans+len(vis))
