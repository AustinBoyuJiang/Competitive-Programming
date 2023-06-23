n,m,q=list(map(int,input().split()))
Map=[None for i in range(n)]
Sum=[[0 for j in range(m+1)] for i in range(n+1)]
for i in range(1,n+1):
    Map[i-1]=list(map(int,input().split()))
    for j in range(1,m+1):
        Sum[i][j]=Map[i-1][j-1]+Sum[i][j-1]+Sum[i-1][j]-Sum[i-1][j-1]
for i in range(q):  
    x1,y1,x2,y2=list(map(int,input().split()))
    print(Sum[x2][y2]-Sum[x2][y1-1]-Sum[x1-1][y2]+Sum[x1-1][y1-1])
