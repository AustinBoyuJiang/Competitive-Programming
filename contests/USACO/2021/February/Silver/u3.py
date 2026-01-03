n=int(input())
cnt=0
Map=[list(map(int,input().split())) for i in range(n)]
hun=[[Map[i][j]==100 for j in range(n)] for i in range(n)]
shun=[[Map[i][j]<100 for j in range(n)] for i in range(n)]
prefixHun=[[0 for j in range(n+1)] for i in range(n+1)]
prefixShun=[[0 for j in range(n+1)] for i in range(n+1)]
for i in range(1,n+1):
    for j in range(1,n+1):
        prefixHun[i][j]=hun[i-1][j-1]+prefixHun[i-1][j-0]+prefixHun[i-0][j-1]-prefixHun[i-1][j-1]
        prefixShun[i][j]=shun[i-1][j-1]+prefixShun[i-1][j-0]+prefixShun[i-0][j-1]-prefixShun[i-1][j-1]
for x1 in range(n):
    for y1 in range(n):
        for x2 in range(x1+1):
            for y2 in range(y1+1):
                cntHun=prefixHun[x1+1][y1+1]-prefixHun[x2][y1+1]-prefixHun[x1+1][y2]+prefixHun[x2][y2]
                cntShun=prefixShun[x1+1][y1+1]-prefixShun[x2][y1+1]-prefixShun[x1+1][y2]+prefixShun[x2][y2]
                if(cntHun>0 and cntShun==0):cnt+=1
print(cnt)
