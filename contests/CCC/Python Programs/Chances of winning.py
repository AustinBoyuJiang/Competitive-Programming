def sor(ab,ba):
    if(int(ab)<=int(ba)):return str(ab)+str(ba)
    else:return str(ba)+str(ab)
def big():
    if(max(j)!=j[a-1]):return False
    abc=0
    for abd in j:
        if(abd==max(j)):abc=abc+1
    if(abc>1):return False
    else:return True
a=int(input())
b=int(input())
c=[]
d=[]
f=[0,0,0,0]
g=["12","13","14","23","24","34"]
for i in range(b):
    e=str(input()).split(" ")
    c.append(list(map(int,(e[0]+" "+e[1]).split(" "))))
    d.append(list(map(int,(e[2]+" "+e[3]).split(" "))))
for i in range(len(d)):
    if(d[i][0]>d[i][1]):f[c[i][0]-1]=f[c[i][0]-1]+3
    elif(d[i][0]<d[i][1]):f[c[i][1]-1]=f[c[i][1]-1]+3
    else:
        f[c[i][0]-1]=f[c[i][0]-1]+1
        f[c[i][1]-1]=f[c[i][1]-1]+1
    g.remove(sor(c[i][0],c[i][1]))

y=0
for i in g:
    h=0
    j=f
    j[int(i[0])-1]=j[int(i[0])-1]+3
    if(big()==True):h=h+1
    j=f
    j[int(i[1])-1]=j[int(i[1])-1]+3
    if(big()==True):h=h+1
    j=f
    j[int(i[0])-1]=j[int(i[0])-1]+1
    j[int(i[1])-1]=j[int(i[1])-1]+1
    if(big()==True):h=h+1
    if(h!=0):
        if(y==0):y=h
        else:y=y*h
print(y)
