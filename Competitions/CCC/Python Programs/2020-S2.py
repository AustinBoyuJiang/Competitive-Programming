def prime(n):
    if(n==1):return False
    for i in range(2,int(n**0.5+1)):
        if(n%i==0):return False
    return True

def find(n):
    i=0
    while(not(prime(n-i) and prime(n+i)) ):
        i+=1
    print(n-i,n+i)

t=int(input())
for i in range(t):
    n=int(input())
    find(n)
