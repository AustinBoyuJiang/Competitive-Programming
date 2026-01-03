def time(elem):
    return elem[0]
n=int(input())
speed=[list(map(int,input().split())) for i in range(n)]
speed.sort(key=time)
maxSpeed=0
for i in range(1,n):
    maxSpeed=max(maxSpeed,abs(speed[i][1]-speed[i-1][1])/(speed[i][0]-speed[i-1][0]))
print(maxSpeed)
