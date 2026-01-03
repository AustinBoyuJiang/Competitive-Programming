digit=['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']

def toTen(n,sys):
    sys=int(sys)
    cnt=0
    for i in range(len(n)):
        cnt+=digit.index(n[len(n)-i-1])*sys**i
    return cnt

def toN(n,sys):
    n=int(n)
    sys=int(sys)
    if(n==0):return '0'
    cnt=''
    while(n>0):
        cnt=digit[n%sys]+cnt
        n=int(n/sys)
    return cnt

# n,sysNow,sysTo=input().split()
# print(toN(toTen(n,sysNow),sysTo))
for i in range(50,101):
    print(toN(toTen(str(i),10),8))