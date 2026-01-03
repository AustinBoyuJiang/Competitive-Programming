def find():
    global a,e,number
    b="Roland"
    while(1):
        for i1 in range(5):
            c=e[i1]
            d="t"
            for i in range(4):
                if(c[i]>number[i]):d="f"
            if(d=="t"):
                n=i1
                break
            elif(i1==4):
                return b
        for i in a[n]:
            number[i]=number[i]-1
        if(b=="Roland"):b="Patrick"
        else:b="Roland"
    
a=[[0,0,1,3,3],[0,1,2,3],[2,2,3],[1,1,1],[0,3]]
e=[[2,1,0,2],[1,1,1,1],[0,0,2,1],[0,3,0,0],[1,0,0,1]]
for i in range(int(input())):
    number=list(map(int,str(input()).split(" ")))
    print(find())
