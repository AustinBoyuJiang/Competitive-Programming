def dfs(This,Last,step):
   if(result[This]!=0):
      if(result[This]=='Infinity'):
         return True
      elif(cow[Last][0]=='N' and cow[This][1]+result[This]>cow[Last][1]):
         return True
      elif(cow[Last][0]=='E' and cow[This][2]+result[This]>cow[Last][2]):
         return True
      else:
         return False
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
   result[This]='Infinity'
   for i in range(len(minCow)):
       if(dfs(minCow[i][0],This,minCow[i][1])):
           result[This]=minCow[i][1]
           break
   if(result[This]=='Infinity'):
      return True
   elif(cow[Last][0]=='N' and cow[This][1]+result[This]>cow[Last][1]):
      return True
   elif(cow[Last][0]=='E' and cow[This][2]+result[This]>cow[Last][2]):
      return True
   else:
      return False

n=int(input())
cow=[]
result=[0 for i in range(n)]
for i in range(n):
    cow+=[input().split()]
    cow[i][1]=int(cow[i][1])
    cow[i][2]=int(cow[i][2])
for i in range(n):
    dfs(i,-1,0)
for i in result:
    print(i)
