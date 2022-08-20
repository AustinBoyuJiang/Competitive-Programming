a=int(input())
c=100
d=100
for i in range(a):
    b=str(input()).split(" ")
    if(b[0]>b[1]):
        d=d-int(b[0])
    elif(b[1]>b[0]):
        c=c-int(b[1])
print(c)
print(d)
