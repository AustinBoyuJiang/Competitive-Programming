n,m,q=list(map(int,input().split()))
Map=[list(map(int,input().split())) for i in range(n)]
record=[[0 for i in range(m+1)] for j in range(n+1)]
Sum=[[0 for i in range(m+1)] for j in range(n+1)]
for i in range(q):
    x1,y1,x2,y2,c=list(map(int,input().split()))
    record[x1-1][y1-1]+= c
    record[x1-1][y2]-=c
    record[x2][y1-1]-=c
    record[x2][y2]+= c
for i in range(1,n+1):
    for j in range(1,m+1):
        Sum[i][j]=record[i-1][j-1]+Sum[i][j-1]+Sum[i-1][j]-Sum[i-1][j-1]
        print(Map[i-1][j-1]+Sum[i][j],end=' ')
    print('')
