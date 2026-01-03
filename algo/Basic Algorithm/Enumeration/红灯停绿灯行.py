def change1(string):
    t=string.split(":")
    length=len(t)
    res=0
    for i in range(length):
        res+=int(t[i])*60**(length-i-1)
    return res

def change2(s):
    h=s//3600
    s%=3600
    m=s//60
    s%=60
    return "%s:%s:%s"%(str(h).zfill(2),str(m).zfill(2),str(s).zfill(2))

t=[]
g=[]
r=[]
n=int(input())
for i in input().split(" "):
    t.append(change1(i))
for i in range(n-2):
    inp=input().split()
    g.append(change1(inp[0]))
    r.append(change1(inp[1]))
ans=t[0]
for i in range(n-2):
    now=ans%(g[i]+r[i])
    if(now>=g[i]): ans+=g[i]+r[i]-now
    ans+=t[i+1]
print(change2(ans))
