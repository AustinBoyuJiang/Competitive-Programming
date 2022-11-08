n=int(input())
t1=str(input())
t2=str(input())
t1c=t1.split(" ")
t2c=t2.split(" ")
t1=0
t2=0
max=0
for i in range (n):
    t1=t1+int(t1c[i])
    t2=t2+int(t2c[i])
    if(t1==t2):
        max=i+1
print(max)
