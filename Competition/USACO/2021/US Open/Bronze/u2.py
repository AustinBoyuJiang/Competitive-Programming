m,n = list(map(int,input().split()))
members = input().split()
levels = {members[i]:0 for i in range(n)}
for i in range(m):
    order = input().split()
    for j in range(1,n):
        if(order[j]<order[j-1]):
            for k in range(j,n):
                levels[order[k]]+=1
for i in range(n):
    for j in range(n):
        if(i==j):
            print("B",end = "")
        elif(levels[members[i]]>levels[members[j]]):
            print(1,end = "")
        elif(levels[members[i]]<levels[members[j]]):
            print(0,end = "")
        else:
            print("?",end = "")
    print("")
