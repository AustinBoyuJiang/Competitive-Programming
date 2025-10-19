def bigger(result,n):
    s=0
    for i in result:
        if(i==n):s=s+1
    if(s>=2):return True
    else:return False

def another(lists,n):
    if(lists[0]==n):return lists[1]
    else:return lists[0]

order=[[1,7],[1,4],[2,1],[3,4]]
have=[]
a=[]
b=[]
g=[5,6]

while(1):
    a=[None,None]
    a[0]=int(input())
    a[1]=int(input())
    if(a[0]==5 and g[0]==5):g[0]=0
    elif(a[1]==5 and g[0]==5):g[0]=0
    if(a[0]==6 and g[1]==6):g[1]=0
    elif(a[1]==6 and g[1]==6):g[1]=0
    if(a[0]==0 and a[1]==0):break
    else:order.append(a)
if(5 in g):order.append([4,5])
if(6 in g):order.append([5,6])

def sor(result,n):
    global order,have,a,b
    old=[]
    new=[]
    b=[]
    for i in order:
        if(n in i and not(i in have)):
            old.append(i)
            b.append(another(i,n))  
    b.sort()
    for i in b:
        for i1 in old:
           if(i in i1):
               new.append(i1)
               break
    if(len(new)==0):
        a=result
        return a
    for i in new:
        have.append(i)
        if(i[0]==n):
            if(i[1] in result):
                a=result
                return a
            result.append(i[1])
            sor(result,i[1])
        else:
            if(i[0] in result):
                a=result
                return a
            result.insert(result.index(n),i[0])
            sor(result,i[0])

sor([1],1)
print(str(a[0])+" "+str(a[1])+" "+str(a[2])+" "+str(a[3])+" "+str(a[4])+" "+str(a[5])+" "+str(a[6]))
