import math

def create(s):
    List=[]
    for i1 in range(n):
        List.append(1)
        s-=1
    for i1 in range(s):
        for i2 in range(n):
            if(List[i2]<6):
                List[i2]+=1
                break
    return List

def  combination(List):
    global visit1
    Lists=[List]
    for i1 in range(n-2,-1,-1):
        for i2 in range(i1+1,n):
            t=List[0:]
            if(List[i1]-2>=List[i2] and List[i2]<List[i2-1] and List[i1]>List[i1+1]):
                t[i1]-=1;t[i2]+=1
                if(not(t in visit1)):
                    visit1+=[t]
                    Lists+=combination(t)
    return Lists

def permutation(List,This=[],n=0):
    global visit2,visit3
    if(n>=len(List)):
        if(This==[] or This in visit3):
            return[]
        else:
            visit3+=[This]
            return [This]
    result=[]
    for i in range (len(List)):
        if(not(i in visit2)):
            visit2+=[i]
            result+=permutation(List,This+[List[i]],n+1)
            visit2.remove(i)
    return result

def calculate(s):
    global visit1,visit2,visit3
    Map=[]
    visit1=[]
    for i1 in combination(create(s)):
        visit2=[];visit3=[]
        Map+=permutation(i1)
    Map.sort()
    return len(Map)

def main():
    global n
    n=int(input())
    number=[0 for s in range(n*5+1)]
    for s in range(math.ceil((n*5+1)/2)):
        number[s]=[n+s,calculate(s+n)/6**n]
        number[(s+1)*-1]=[n*6-s,number[s][1]]
    print(number)

if(__name__=='__main__'):
    main()
