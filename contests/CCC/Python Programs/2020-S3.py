a=input()
b=input()
la=len(a)
lb=len(b)
ca=[[0]*26]
cb=[[0]*26]
answer=0
hashMap=[0 for i in range(1000000)]
for i in range(la):
    ca+=[ca[i][0:]]
    ca[i+1][ord(a[i])-97]+=1
for i in range(lb):
    cb+=[cb[i][0:]]
    cb[i+1][ord(b[i])-97]+=1
for i in range(lb-la+1):
    if([cb[i+la][j]-cb[i][j] for j in range(26)]==ca[la]):
        if(not(hashMap[hash(b[i:i+la-1])%1000000])):
            hashMap[hash(b[i:i+la-1])%1000000]=1
            answer+=1
print(answer)
