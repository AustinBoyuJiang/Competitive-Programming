def string(lists):
    a=""
    for i1 in lists:
        a=a+i1
    return a

yn="no"
test1=str(input())
test3=str(input())
test2=[]
for i in test3:
    test2.append(i)
for i in range(len(test2)):
    test2.append(test2[0])
    del test2[0]
    if(string(test2) in test1):
        yn="yes"
print(yn)
    
    
