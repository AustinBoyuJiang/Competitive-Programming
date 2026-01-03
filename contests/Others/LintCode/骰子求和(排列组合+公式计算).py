import math

def create(n,i):
    num=[]
    for i1 in range(n):
        num.append(1)
        i-=1
    for i1 in range(i):
        for i2 in range(n):
            if(num[i2]<6):
                num[i2]+=1
                i-1
                break
    return num

def  combination(n,num):
    global visit
    sum=permutation(n,num)
    for i1 in range(n-2,-1,-1):
        for i2 in range(i1+1,n):
            t=[]
            for i in num:
                t.append(i)
            if(num[i1]-2>=num[i2] and num[i2]<num[i2-1] and num[i1]>num[i1+1]):
                t[i1]-=1
                t[i2]+=1
                if(not(t in visit)):
                    visit.append(t)
                    sum+=combination(n,t)
    return sum

def permutation(n,num):
    number=[0,0,0,0,0,0]
    s=factorial(n)
    for i in num:
        number[i-1]+=1
    for i in number:
        s=s/factorial(i)
    return s

def factorial(x):
    product=1
    for i in range(1,x+1):
        product=product*i
    return product

def calculate(n,i):
    global visit
    visit=[]
    return combination(n,create(n,i))

def main():
    n=int(input())
    number=[]
    for i in range(n,n+math.ceil(n*2.5+0.5)):
        number.append([i,calculate(n,i)/6**n])
    for i in range(n+math.ceil(n*2.5+0.5),n*6+1):
        number.append([i,number[n*6-i][1]])
    print(number)

if(__name__=='__main__'):
    main()
