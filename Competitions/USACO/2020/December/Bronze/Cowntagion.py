n=int(input())
answer=0
son=[0 for i in range(n+1)]
for i in range(n-1):
    inp=list(map(int,input().split()))
    son[inp[0]]+=1
    son[inp[1]]+=1
for i in range(1,n+1):
    if(i!=1):
        son[i]-=1
    day,cow=0,1
    while(cow-1<son[i]):
        day+=1
        cow*=2
    answer+=son[i]+day
print(answer)
