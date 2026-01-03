nums=[-7,-2,-1,-6]
dpMax=nums[0:]
dpMin=nums[0:]
for i in range(1,len(nums)):
    dpMax[i]=max(dpMin[i-1]*nums[i],dpMax[i-1]*nums[i],nums[i])
    dpMin[i]=min(dpMin[i-1]*nums[i],dpMax[i-1]*nums[i],nums[i])
print(max(dpMax))
