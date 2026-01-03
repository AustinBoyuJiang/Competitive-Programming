'''
def check(string):
    length=len(string)
    num=[0]*length
    char=[0]*26
    step=0
    for i in range(length):
        char[ord(string[i])-65]+=1
    for j in range(26):
        if(char[j]):
            draw=0
            for i in range(length):
                if(j==ord(string[i])-65 and draw==0):
                    step+=1
                    draw=1
                    num[i]=step
                elif(j<=ord(string[i])-65 and draw==1):num[i]=step
                else:draw=0
    print(num)
    return step
print(check(list('AABBACBA')))
'''
def check(string):
    if(string==[]):return 0
    up,down=1,0
    maxDepth=up
    minDepth=down
    for i in range(1,len(string)):
        if(string[i]>string[i-1]):
            up+=1
            down+=1
        elif(string[i]<string[i-1]):
            down-=1
            minDepth=min(minDepth,down)
        maxDepth=max(maxDepth,up-minDepth)
    return maxDepth

def answer(a,b):
    return check(string[0:a-1])+check(string[b:n])

n,q=list(map(int,input().split()))
string=list(input())
for i in range(q):
    a,b=list(map(int,input().split()))
    print(answer(a,b))
