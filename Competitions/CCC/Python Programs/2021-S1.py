n=int(input())
height=list(map(int,input().split()))
width=list(map(int,input().split()))
answer=0
for i in range(n):
    answer+=(height[i]+height[i+1])*width[i]/2
print(answer)
