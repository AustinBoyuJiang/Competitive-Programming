n=input()
h,v=0,0
for i in range(len(n)):
    h+=n[i]=='H'
    v+=n[i]=='V'
if(h%2==0 and v%2==0):
    print(1,2)
    print(3,4)
if(h%2==1 and v%2==0):
    print(3,4)
    print(1,2)
if(h%2==0 and v%2==1):
    print(2,1)
    print(4,3)
if(h%2==1 and v%2==1):
    print(4,3)
    print(2,1)
