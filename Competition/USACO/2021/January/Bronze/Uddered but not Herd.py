import math
a=input()
b=input()
al=len(a)
bl=len(b)
i=0
j=0
while(j!=bl):
    if(a[i%al]==b[j]):j+=1
    i+=1
print(math.ceil(i/al))
