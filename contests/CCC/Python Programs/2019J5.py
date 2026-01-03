rule=[]
for i in range(3):
    rule+=[input().split(' ')]
step,a,b=input().split(' ')
step=int(step)

task1=[]
task2=[]
task1+=[[0,[[0,0,a]]]]
task2+=[[step,[[0,0,b]]]]
while(task1 or task2):
    This1=task1[-1][0:]
    This2=task2[-1][0:]
    task1.pop(-1)
    task2.pop(-1)
    if(This1[0]==step and This1[1][-1][2]==b):
        for i in range(1,len(This1[1])):
            print(This1[1][i][0],This1[1][i][1],This1[1][i][2])
        break
    if(This2[0]==0 and This2[1][0][2]==a):
        for i in range(1,len(This2[1])):
            print(This2[1][i][0],This2[1][i][1],This2[1][i][2])
        break
    for i in range(3):
        for j in range(0,max(len(This1[1][-1][2])-len(rule[i][0])+1,len(This2[1][0][2])-len(rule[i][1])+1)):
            if(j<len(This1[1][-1][2])-len(rule[i][0])+1):
                if(This1[1][-1][2][j:j+len(rule[i][0])]==rule[i][0]):
                    if(This1[0]<step):
                        after=This1[1][-1][2][0:j]+rule[i][1]+This1[1][-1][2][j+len(rule[i][0]):len(This1[1][-1][2])]
                        Next=[This1[0]+1,This1[1][0:]+[[i+1,j+1,after]]]
                        task1+=[Next[0:]]
            if(j<len(This2[1][0][2])-len(rule[i][1])+1):
                if(This2[1][0][2][j:j+len(rule[i][1])]==rule[i][1]):
                    if(This2[0]>0):
                        after=This2[1][0][2][0:j]+rule[i][0]+This2[1][0][2][j+len(rule[i][1]):len(This2[1][0][2])]
                        Next=[This2[0]-1,[[0,0,after]]+[[i+1,j+1,This2[1][0][2]]]+This2[1][1:]]
                        task2+=[Next[0:]]
                        
"""
AA AB
AB BB
B AA
4 AB AAAB
"""
"""
def dfs(string,n):
    for i in range(3):
        for j in range(0,len(string)-len(rule[i][0])+1):
            if(string[j:j+len(rule[i][0])]==rule[i][0]):
                after=string[0:j]+rule[i][1]+string[j+len(rule[i][0]):len(string)]
                if(n<step-1):
                    r=dfs(after,n+1)
                    if(r!=None):
                        return [str(i+1)+' '+str(j+1)+' '+after]+r
                elif(n==step-1 and after==b):
                    return [str(i+1)+' '+str(j+1)+' '+after]

rule=[]
for i in range(3):
    rule+=[input().split(' ')]
step,a,b=input().split(' ')
step=int(step)
for i in dfs(a,0):
    print(i)
"""
