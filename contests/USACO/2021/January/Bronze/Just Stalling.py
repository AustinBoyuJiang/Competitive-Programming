n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
answer=1
num=[0 for i in range(n)]
for i in range(n):
    for j in range(n):
        if(a[i]<=b[j]):num[i]+=1
num.sort()
for i in range(n):
    answer*=num[i]-i
print(max(0,answer))
