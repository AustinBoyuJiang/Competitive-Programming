n=int(input())
m=int(input())
k=int(input())
answer=0
row=[[0 for j in range(m+1)] for i in range(n+1)]
column=[[0 for j in range(m+1)] for i in range(n+1)]
for i in range(k):
    a,b=input().split()
    if(a=='R'):
        row[int(b)][1]+=1
    if(a=='C'):
        column[1][int(b)]+=1
for i in range(1,n+1):
    for j in range(1,m+1):
        row[i][j]+=row[i][j-1]
        column[i][j]+=column[i-1][j]
        answer+=(row[i][j]+column[i][j])%2
print(answer)
