n=int(input())
t=1/6
a={}
b={1:t,2:t,3:t,4:t,5:t,6:t}
for i1 in range(n-1):
    a=b
    b={}
    for i2 in a:
        for i3 in range(1,7):
            if(i2+i3 in b):
                b[i2+i3]+=a[i2]*t
            else:
                b[i2+i3]=a[i2]*t
number=[]
for i in range(n*5+1):
    number.append([n+i,b[n+i]])
print(number)
'''
class Solution:
    # @param {int} n an integer
    # @return {tuple[]} a list of tuple(sum, probability)
    def dicesSum(self, n):
        # Write your code here
        t =1/6
        dic = {1: t, 2: t, 3: t, 4: t, 5:t, 6: t}
        k = 1
        while k < n:
            dic1 = {}
            for x in range(1, 7):
                for i in dic.keys():
                    z = x + i
                    if z in dic1.keys():
                        dic1[z]=dic1[z]+dic[i]*t
                        continue
                    dic1.update({z:dic[i]*t})
            dic = dic1
            k += 1
        re = []
        for k,v in dic.items():
            re.append([k,v])
        return re
a=Solution()
print(a.dicesSum(int(input())))
'''
