def BinarySearch(x):
    left,right=0,n-1
    while(left<=right):
        mid=(left+right)//2
        if(Map[mid]<x):left=mid+1
        elif(Map[mid]>=x):right=mid-1
    return n-left
n,q=list(map(int,input().split()))
Map=list(map(int,input().split()))
Map.sort()
for i in range(q):
    print(BinarySearch(int(input())))
