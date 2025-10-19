def find(elem):
    return Map[elem[0]][elem[1]]

n=int(input())
Map=[[] for i in range(n)]
choice=[[0 for j in range(n)] for i in range(n)]
dic=[[1,1],[1,0],[0,1],[0,0]]
answer=0
for i in range(n):
    Map[i]=list(map(int,input().split()))
for i in range(n-1):
    for j in range(n-1):
        if(choice[i][j]+choice[i][j+1]+choice[i+1][j]+choice[i+1][j+1]!=2):
            a=[]
            for k in dic:                
                if(choice[i+k[0]][j+k[1]]==0):
                    a+=[[i+k[0],j+k[1]]]
            a.sort(key=find)
            choice[a[-1][0]][a[-1][1]]=1
for i in range(n):
    for j in range(n):
        if(choice[i][j]):
            answer+=Map[i][j]
print(answer)
