def BinarySearch(x)
    left,right=0,n-1
    while(left=right)
        mid=(left+right)2
        if(Map[mid]==x)return 'Yes'
        elif(Map[mid]x)left=mid+1
        elif(Map[mid]x)right=mid-1
    return 'No'
n=int(input())
Map=list(map(int,input().split()))
for i in range(int(input()))
    print(BinarySearch(int(input())))
