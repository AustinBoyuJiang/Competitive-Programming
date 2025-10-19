def prime(number):
    n=0
    s=0
    for i in range (number):
        n=n+1
        if(number%n==0):
            s=s+1
    if(s<=2):
        return True
    else:
        return False

def factor(before,number):
    if(before==True):
        return [number,1]
    a=[None,None]
    b=2
    for i in range(number-1):
        if(number%b==0):
            a=[b,int(number/b)]
            break
        b=b+1
    if(a[1]==1):
        a=[1,number]
    return a

a=int(input())
n=a
b=0
while(n>1):
    before=prime(n)
    n=n-factor(before,n)[1]
    b=b+factor(before,n)[0]
print(b)
