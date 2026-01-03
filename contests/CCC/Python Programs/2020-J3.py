s=[None,None]
b=[None,None]
for i in range(int(input())):
    a=input().split(",")
    a[0]=int(a[0])
    a[1]=int(a[1])
    if(s[0]!=None):
        if(a[0]<s[0]):
            s[0]=a[0]
    else:
        s[0]=a[0]
        
    if(s[1]!=None):
        if(a[1]<s[1]):
            s[1]=a[1]
    else:
        s[1]=a[1]

    if(b[0]!=None):
        if(a[0]>b[0]):
            b[0]=a[0]
    else:
        b[0]=a[0]
        
    if(b[1]!=None):
        if(a[1]>b[1]):
            b[1]=a[1]
    else:
        b[1]=a[1]

print(str(s[0]-1)+","+str(s[1]-1))
print(str(b[0]+1)+","+str(b[1]+1))
