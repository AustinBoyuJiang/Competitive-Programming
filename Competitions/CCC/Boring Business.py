a=[[0,-1],[0,-2],[0,-3],[1,-3],[2,-3],[3,-3],[3,-4],[3,-5],[4,-5],[5,-5],[5,-4],[5,-3],[6,-3],[7,-3],[7,-4],[7,-5],[7,-6],[7,-7],[6,-7],[5,-7],[4,-7],[3,-7],[2,-7],[1,-7],[0,-7],[-1,-7],[-1,-6],[-1,-5]]
x=-1
y=-5
g=[0,0]
while(1):
    b=str(input()).split(" ")
    d="safe"
    if(b[0]=="u"):
        for i in range(int(b[1])):
            y=y+1
            if([x,y] in a):d="DANGER"
            a.append([x,y])
    elif(b[0]=="d"):
        for i in range(int(b[1])):
            y=y-1
            if([x,y] in a):d="DANGER"
            a.append([x,y])
    elif(b[0]=="l"):
        for i in range(int(b[1])):
            x=x-1
            if([x,y] in a):d="DANGER"
            a.append([x,y])
    elif(b[0]=="r"):
        for i in range(int(b[1])):
            x=x+1
            if([x,y] in a):d="DANGER"
            a.append([x,y])
    else:break
    print(str(x)+" "+str(y)+" "+d)
    if(d=="DANGER"):break
