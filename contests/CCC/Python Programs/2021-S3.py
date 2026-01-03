'''
p[i]: 每个同学所在的初始位置
w[i]: 每个同学的移动速度
d[i]: 每个同学可以听到的范围
pos[i]: 演讲者所在的位置
每个同学可以听到的范围看作一个区间
区间右端点的值和区间左端点的值分别进行排序以便二分
pos[i]左边的人移到目标所用时间公式: w[i]*(pos[i]-(p[i]+d[i]))
pos[i]的值是不确定的，w[i],p[i],d[i]都是确定的，所以提取公因数: w[i]*pos[i]-w[i]*(p[i]+d[i])
右边的公式也是一样: w[i]*(p[i]-d[i])-w[i]*pos[i]
左边公式可以看成两部分: w[i]和w[i]*(p[i]+d[i])
双指针找出pos[i]左边的所有人和右边的所有人
四个部分用前缀和快速计算出所有人的移动时间
遍历所有区间的两端寻找出最短时间并输出最优答案
'''
n=int(input())
ans=float('inf')
pos=[]
sortLeft,sortRight=[],[]
prefixLeft1,prefixLeft2=[0],[0]
prefixRight1,prefixRight2=[0],[0]
for i in range(n):
    p,w,d=list(map(int,input().split()))
    pos.append(p-d)
    pos.append(p+d)
    sortLeft.append([p,d,w,p+d])
    sortRight.append([p,d,w,p-d])
pos.sort()
sortLeft.sort(key=lambda assay: assay[3])
sortRight.sort(key=lambda assay: assay[3])
for i in range(n):
    prefixLeft1.append(prefixLeft1[i]+sortLeft[i][2])
    prefixRight1.append(prefixRight1[i]+sortRight[i][2])
    prefixLeft2.append(prefixLeft2[i]+sortLeft[i][2]*(sortLeft[i][0]+sortLeft[i][1]))
    prefixRight2.append(prefixRight2[i]+sortRight[i][2]*(sortRight[i][0]-sortRight[i][1]))
peopleLeft=0
peopleRight=0
for i in range(n*2):
    while(sortLeft[peopleLeft][3]<pos[i]):
        peopleLeft+=1
    while(peopleRight<n and sortRight[peopleRight][3]<=pos[i]):
        peopleRight+=1
    leftTime=pos[i]*(prefixLeft1[peopleLeft]-prefixLeft1[0])-(prefixLeft2[peopleLeft]-prefixLeft2[0])
    rightTime=(prefixRight2[n]-prefixRight2[peopleRight])-pos[i]*(prefixRight1[n]-prefixRight1[peopleRight])
    time=leftTime+rightTime
    ans=min(ans,time)
print(ans)
