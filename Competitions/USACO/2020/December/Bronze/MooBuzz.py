inp=open('moobuzz.in','r')
out=open('moobuzz.out','w')
n=int(inp.read())
check=lambda m:m-m//3-m//5+m//15
l,r=n,n*2
answer=n*2
while(l<=r):
    m=(l+r)//2
    if(check(m)==n):answer=min(answer,m)
    if(check(m)<n):l=m+1
    elif(check(m)>=n):r=m-1
out.write(str(answer))
inp.close()
out.close()
