def dfs(This,Last,lastStep):
    if(path[This]!=None):
        if(cowStep[This]==float('inf')):
            return [This]
        elif(cow[Last][0]=='N' and cow[This][1]+cowStep[This]>cow[Last][1]):
            return path[This]
        elif(cow[Last][0]=='E' and cow[This][2]+cowStep[This]>cow[Last][2]):
            return path[This]
        else:
            return []
    minCow=[]
    for Next in range(n):
        if(cow[This][0]=='N' and cow[Next][0]=='E'):
            if(cow[Next][1]<cow[This][1] and cow[Next][2]>cow[This][2]):
                if(cow[This][1]-cow[Next][1]<cow[Next][2]-cow[This][2]):
                    minCow+=[[Next,cow[Next][2]-cow[This][2]]]
        if(cow[This][0]=='E' and cow[Next][0]=='N'):
            if(cow[Next][1]>cow[This][1] and cow[Next][2]<cow[This][2]):
                if(cow[This][2]-cow[Next][2]<cow[Next][1]-cow[This][1]):
                    minCow+=[[Next,cow[Next][1]-cow[This][1]]]
    minCow.sort(key=lambda array:array[1])
    cowStep[This]=float('inf')
    allStep=[]
    for i in range(len(minCow)):
        allStep=dfs(minCow[i][0],This,minCow[i][1])
        if(allStep!=[]):
            cowStep[This]=minCow[i][1]
            break
    if(cowStep[This]==float('inf')):
        path[This]=[This]
        return [This]
    elif(cow[Last][0]=='N' and cow[This][1]+cowStep[This]>cow[Last][1]):
        path[This]=[This]+allStep
        return [This]+allStep
    elif(cow[Last][0]=='E' and cow[This][2]+cowStep[This]>cow[Last][2]):
        path[This]=[This]+allStep
        return [This]+allStep
    else:
        return []

n=int(input())
cow=[]
path=[None for i in range(n)]
cowStep=[0 for i in range(n)]
task=[]
visit=[1 for i in range(n)]
export=[[0 for j in range(n)] for i in range(n)]
entrance=[[0 for j in range(n)] for i in range(n)]
result=[0 for i in range(n)]
for i in range(n):
    cow+=[input().split()]
    cow[i][1]=int(cow[i][1])
    cow[i][2]=int(cow[i][2])
for i in range(n):
    answer=dfs(i,i,0)
    for j in range(1,len(answer)):
        export[answer[j-1]][answer[j]]=1
        entrance[answer[j]][answer[j-1]]=1
for i in range(n):
    if(entrance[i]==[0]*n):
        task+=[i]
        visit[i]=0
while(task):
    this=task.pop(0)
    for i in range(n):
        if(export[this][i]):
            if(visit[i]):
                entrance[i][this]=0
                result[i]+=result[this]+1
                if(entrance[i]==[0]*n):
                    task+=[i]
                    visit[i]=0
for i in range(n):
    print(result[i])
