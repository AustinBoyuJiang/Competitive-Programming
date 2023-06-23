length=int(input())
width=int(input())
Map=[]
visit=[]
direction=[[1,0],[0,1],[-1,0],[0,-1]]
for i in range(width):
    Map+=[list(input())]

def dfs(x,y):
    if([x,y]==[length-1,width-1]):return [[x,y]]
    path=[]
    for i in direction:
        nextx,nexty=x+i[0],y+i[1]
        if(nextx>=0 and nexty>=0 and nextx<length and nexty<width and Map[nexty][nextx]!=1 and not [nextx,nexty] in visit):
            visit.append([x,y])
            answer=dfs(nextx,nexty)
            visit.remove([x,y])
            if([length-1,width-1] in answer and (path==[] or len([[x,y]]+answer) <len(path))):path=[[x,y]]+answer
    return path
print(dfs(0,0))
