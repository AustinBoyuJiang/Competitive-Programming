a=int(input())
b=input()
c=0
d=0
for i in range(a):
    if(b[i]=="A"):c=c+1
    else:d=d+1
if(c>d):print("A")
elif(d>c):print("B")
else:print("Tie")
