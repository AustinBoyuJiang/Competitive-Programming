def dfs(List,length,repeat,This=[],n=0):
    global visit1,visit2
    if(n==0):visit1,visit2=[],[]
    elif(n>=length):
        if(This==[] or This in visit2):return []
        else:visit2+=[This];return [This]
    result=[]
    for i in range (len(List)):
        if(repeat):
            result+=dfs(List,length,repeat,This+[List[i]],n+1)
        else:
            if(not(i in visit1)):
                visit1+=[i]
                result+=dfs(List,length,repeat,This+[List[i]],n+1)
                visit1.remove(i)
    return result

def find(List):
    brackets=[[[0,0],[0,0],[0,0],[0,0]],
              [[1,0],[0,1],[0,0],[0,0]],
              [[0,0],[1,0],[0,1],[0,0]],
              [[0,0],[0,0],[1,0],[0,1]],
              [[1,0],[0,0],[0,1],[0,0]],
              [[0,0],[1,0],[0,0],[0,1]],
              [[1,0],[0,1],[1,0],[0,1]],
              [[2,0],[0,1],[0,1],[0,0]],
              [[1,0],[1,0],[0,2],[0,0]],
              [[0,0],[2,0],[0,1],[0,1]],
              [[0,0],[1,0],[1,0],[0,2]]]
    symbols=dfs(['+','-','*','/'],3,True)
    numbers=dfs(List,4,False)
    for number in numbers:
        for symbol in symbols:
            for bracket in brackets:
                formula=''
                for i in range(4):
                    formula+=bracket[i][0]*'('+str(number[i])+bracket[i][1]*')'
                    if(i<3):formula+=str(symbol[i])
                try:
                    if(eval(formula)==24):return formula.replace('*','×').replace('/','÷')
                except:pass

print(find(list(map(int,input().split(" ")))))
