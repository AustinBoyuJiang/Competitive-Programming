while(1):
    a=str(input())
    a=a.split(" ")        
    if(a[0]=="0"):
        break
    del a[0]
    if(a[-1]==""):
        del a[-1]
    a=list(map(int,a))
    b=0
    c=[]
    for i in range(0,len(a)-2):
        c.append(a[i+1]-a[i])
    for i in range(len(c)):
        if(i!=0 and c[0]==c[i]):break
        b=b+1
    print(b)
