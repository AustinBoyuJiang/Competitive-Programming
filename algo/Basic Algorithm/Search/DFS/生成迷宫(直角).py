import random

def inMap(x,y):
    if(x>=thick and y>=thick and x<length-thick and y<width-thick):return True
    else:return False

def create(x,y):
    Map[y][x]=road
    index=[i for i in range(len(direction))]
    for i in range(len(direction)):
        n=index[random.randint(0,len(index)-1)]
        index.remove(n)
        nextx,nexty=x+direction[n][0]*2,y+direction[n][1]*2
        pathx,pathy=x+direction[n][0],y+direction[n][1]
        if(inMap(nextx,nexty) and Map[nexty][nextx]==wall):
            Map[pathy][pathx]=road
            create(nextx,nexty)

def find(x,y):
    if([x,y]==end):return [[x,y]]
    answer=[]
    for i in range(len(direction)):
        nextx,nexty=x+direction[i][0],y+direction[i][1]
        if(inMap(nextx,nexty) and Map[nexty][nextx]!=wall and not [nextx,nexty] in visit):
            visit.append([x,y])
            choise=[[x,y]]+find(nextx,nexty)
            visit.remove([x,y])
            if(end in choise and (answer==[] or len(choise)<len(answer))):answer=choise
    return answer

length=int(input('Length: '))
width=int(input('Width: '))
thick=int(input('Thick: '))
start=[thick,thick]
end=[length-thick-2+length%2,width-thick-2+width%2]
wall='●'
road='  '
path='○'
visit=[]
direction=[[1,0],[0,1],[-1,0],[0,-1]]
Map=list(list(wall for i in range(length)) for i in range(width))
create(start[0],start[1])
result=find(start[0],start[1])

print('Start: '+str(start[0]+1)+','+str(start[1]+1))
print('End: '+str(end[0]+1)+','+str(end[1]+1))
print('')
for i in result:
    Map[i[1]][i[0]]=path
for i1 in range(width):
    for i2 in range(length):
        print(Map[i1][i2],end='')
    print('')
input()
