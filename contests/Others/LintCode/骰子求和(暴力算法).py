def acount(x,num):
    n=0
    for i in num:
        if(i==x):
            n+=1
    return n
    
n=int(input())
a=[]
b=[1,2,3,4,5,6]
for i1 in range(n-1):
    a=b
    b=[]
    for i2 in range(len(a)):
        for i3 in range(6):
            b.append(a[i2]+i3+1)
number=[]
for i in range(n,n*6+1):
    number.append([i,acount(i,b)/6**n])
print(number)

