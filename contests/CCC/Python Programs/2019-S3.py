def dfs(x,y):
    if(x==0 and Map[1][y]!='X' and Map[2][y]!='X'):
        Map[x][y]=Map[1][y]+Map[1][y]-Map[2][y]
        if(Map[x][0]=='X' and Map[x][1]!='X' and Map[x][2]!='X'):dfs(0,0)
        if(Map[x][0]!='X' and Map[x][1]=='X' and Map[x][2]!='X'):dfs(0,1)
        if(Map[x][0]!='X' and Map[x][1]!='X' and Map[x][2]=='X'):dfs(0,2)
    elif(x==1 and Map[0][y]!='X' and Map[2][y]!='X'):
        Map[x][y]=(Map[0][y]+Map[2][y])//2
        if(Map[x][0]=='X' and Map[x][1]!='X' and Map[x][2]!='X'):dfs(1,0)
        if(Map[x][0]!='X' and Map[x][1]=='X' and Map[x][2]!='X'):dfs(1,1)
        if(Map[x][0]!='X' and Map[x][1]!='X' and Map[x][2]=='X'):dfs(1,2)
    elif(x==2 and Map[0][y]!='X' and Map[1][y]!='X'):
        Map[x][y]=Map[1][y]+Map[1][y]-Map[0][y]
        if(Map[x][0]=='X' and Map[x][1]!='X' and Map[x][2]!='X'):dfs(2,0)
        if(Map[x][0]!='X' and Map[x][1]=='X' and Map[x][2]!='X'):dfs(2,1)
        if(Map[x][0]!='X' and Map[x][1]!='X' and Map[x][2]=='X'):dfs(2,2)
    if(y==0 and Map[x][1]!='X' and Map[x][2]!='X'):
        Map[x][y]=Map[x][1]+Map[x][1]-Map[x][2]
        if(Map[0][y]=='X' and Map[1][y]!='X' and Map[2][y]!='X'):dfs(0,0)
        if(Map[0][y]!='X' and Map[1][y]=='X' and Map[2][y]!='X'):dfs(1,0)
        if(Map[0][y]!='X' and Map[1][y]!='X' and Map[2][y]=='X'):dfs(2,0)
    elif(y==1 and Map[x][0]!='X' and Map[x][2]!='X'):
        Map[x][y]=(Map[x][0]+Map[x][2])//2
        if(Map[0][y]=='X' and Map[1][y]!='X' and Map[2][y]!='X'):dfs(0,1)
        if(Map[0][y]!='X' and Map[1][y]=='X' and Map[2][y]!='X'):dfs(1,1)
        if(Map[0][y]!='X' and Map[1][y]!='X' and Map[2][y]=='X'):dfs(2,1)
    elif(y==2 and Map[x][0]!='X' and Map[x][1]!='X'):
        Map[x][y]=Map[x][1]+Map[x][1]-Map[x][0]
        if(Map[0][y]=='X' and Map[1][y]!='X' and Map[2][y]!='X'):dfs(0,2)
        if(Map[0][y]!='X' and Map[1][y]=='X' and Map[2][y]!='X'):dfs(1,2)
        if(Map[0][y]!='X' and Map[1][y]!='X' and Map[2][y]=='X'):dfs(2,2)

Map=[list(map(lambda x: int(x) if(x!='X') else x,input().split())) for i in range(3)]
if(Map==[['X' for j in range(3)] for i in range(3)]):
    Map=[[0 for j in range(3)] for i in range(3)]

for i in range(3):
    for j in range(3):
        if(Map[i][j]=='X'):dfs(i,j)
        
yn=0
for i in range(3):
    for j in range(3):
        if(Map[i][j]=='X'):
            try:
                if(Map[i+1][j]!='X' and Map[i][j+1]!='X'):
                    Map[i][j]=Map[i+1][j]
                    yn=1
                    break
            except:
                try:
                    if(Map[i+1][j]!='X' and Map[i][j-1]!='X'):
                        Map[i][j]=Map[i+1][j]
                        yn=1
                        break
                except:
                    try:
                        if(Map[i-1][j]!='X' and Map[i][j+1]!='X'):
                            Map[i][j]=Map[i-1][j]
                            yn=1
                            break
                    except:
                        try:
                            if(Map[i-1][j]!='X' and Map[i][j-1]!='X'):
                                Map[i][j]=Map[i-1][j]
                                yn=1
                                break
                        except:
                            continue
    if(yn==1):break
    
for i in range(3):
    for j in range(3):
        if(Map[i][j]=='X'):dfs(i,j)
        
while('X' in Map[0] or 'X' in Map[1] or 'X' in Map[2]):
    yn=0
    for i in range(3):
        for j in range(3):
            if(Map[i][j]=='X'):
                try:
                    Map[i][j]=Map[i+1][j]+2
                except:
                    try:
                        Map[i][j]=Map[i-1][j]+2
                    except:
                        try:
                            Map[i][j]=Map[i][j+1]+2
                        except:
                            try:
                                Map[i][j]=Map[i][j-1]+2
                            except:
                                continue
                yn=1
                break
        if(yn==1):
            break
    for i in range(3):
        for j in range(3):
            if(Map[i][j]=='X'):dfs(i,j)
            
for i in range(3):
    for j in range(3):
        if(Map[i][j]=='X'):dfs(i,j)

for i in range(3):
    for j in range(2):
        print(Map[i][j],end=' ')
    print(Map[i][2])
