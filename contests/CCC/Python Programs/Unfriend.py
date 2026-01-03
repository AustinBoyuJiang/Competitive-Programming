import itertools

def comb(lists):
    fd=[]
    v=lists
    v.sort()
    v="".join(list(map(str,v)))
    for i in range(1,len(v)+1):
        ls = itertools.combinations(v,i)
        for si in ls:fd.append(list(map(int,list(si))))
    return fd

def decide(lists,dicts):
    svg=[]
    for i in lists:
        if(len(dicts[i])>=1):
            for i in dicts[i]:
                if(not(i in svg)):
                    return False
        else:
            svg.append(i)
    return True
    
people={}
n=int(input())
for i in range(1,n):
    j=int(input())
    if(not(i in people)):people[i]=[]
    if(not(j in people)):people[j]=[]
    people[j].append(i)
com=[]
for i in people:
    if(i!=n):com.append(i)
a=1
for i in comb(com):
    if(decide(i,people)==True):a=a+1
print(a)
