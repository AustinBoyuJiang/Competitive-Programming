'''
def copy1():
    global Next,This
    Next=[[This[0][0],This[0][1]],[]]
    for i in range(len(This[1])):
        Next[1].append([0,0])
        Next[1][i][0]=This[1][i][0]
        Next[1][i][1]=This[1][i][1]

def copy2():
    queue.append([[Next[0][0],Next[0][1]],[]])
    for i in range(len(Next[1])):
        queue[-1][1].append([0,0])
        queue[-1][1][i][0]=Next[1][i][0]
        queue[-1][1][i][1]=Next[1][i][1]

def find(direction):
    global Next,This
    copy1()
    Next[0][0]+=direction[0]
    Next[0][1]+=direction[1]
    if(Next[0][0]>=0 and Next[0][0]<n and Next[0][1]>=0 and Next[0][1]<m):
        if(Map[Next[0][0]][Next[0][1]]!=1):
            if(not(Next[0] in Next[1])):
                Next[1].append([Next[0][0],Next[0][1]])
                copy2()

inp=input().split(' ')
n=int(inp[0])
m=int(inp[1])
k=int(input())
Map=[]
queue=[[[0,0],[[0,0]]]]
visit=[]
direction=[[1,0],[0,1]]
count=0
for i1 in range(n):
    Map.append([])
    for i2 in range(m):
        Map[i1].append(0)
for i in range(k):
    inp=input().split(' ')
    Map[int(inp[0])-1][int(inp[1])-1]=1
while(len(queue)>0):
    This=queue[0]
    if(This[0]==[n-1,m-1] and not(queue[0] in visit)):
        count+=1
        visit.append(queue[0])
        queue.pop(0)
        continue
    queue.pop(0)
    for i in direction:
        find(i)
print(count)
'''

def bfs(a,b):
    global Next,This
    Next=[This[0],This[1]]
    Next[0]+=a
    Next[1]+=b
    if(Next[0]<n and Next[1]<m):
        if(Map[Next[0]][Next[1]]!=1):
            queue.append([Next[0],Next[1]])

inp=input().split(' ')
n=int(inp[0])
m=int(inp[1])
k=int(input())
count=0
Map=[]
queue=[[0,0]]
for i1 in range(n):
    Map.append([])
    for i2 in range(m):
        Map[i1].append(0)
for i in range(k):
    inp=input().split(' ')
    Map[int(inp[0])-1][int(inp[1])-1]=1
while(len(queue)>0):
    This=queue[0]
    queue.pop(0)
    if(This==[n-1,m-1]):
        count+=1
        continue
    bfs(0,1)
    bfs(1,0)
print(count)
