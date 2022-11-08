def judge(year):
    for i in str(year):
        if(str(year).count(i)>1):
            return False
    return True

y = int(input())
d = y+1
while(judge(d)==False):
    d = d+1
print(d)
