a=list(map(int,str(input()).split(" ")))
b=list(map(int,str(input()).split(" ")))
c=a;d=0
while(c!=b):
    if(b[0]>c[0] and b[1]>c[1]):
        if(abs(b[0]-c[0])>=abs(b[1]-c[1])):c[0]=c[0]+2;c[1]=c[1]+1
        else:c[0]=c[0]+1;c[1]=c[1]+2
    elif(b[0]<c[0] and b[1]<c[1]):
        if(abs(b[0]-c[0])>=abs(b[1]-c[1])):c[0]=c[0]-2;c[1]=c[1]-1
        else:c[0]=c[0]-1;c[1]=c[1]-2
    elif(b[0]>c[0] and b[1]<c[1]):
        if(abs(b[0]-c[0])>=abs(b[1]-c[1])):c[0]=c[0]+2;c[1]=c[1]-1
        else:c[0]=c[0]+1;c[1]=c[1]-2
    else:
        if(abs(b[0]-c[0])>=abs(b[1]-c[1])):c[0]=c[0]-2;c[1]=c[1]+1
        else:c[0]=c[0]-1;c[1]=c[1]+2
    d=d+1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
print(d)
