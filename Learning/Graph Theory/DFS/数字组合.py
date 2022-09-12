"""
def dfs(n,array=[]):
    if(n-sum(array)==0):
        return [array]
    else:
        result=[]
        for i1 in range(array[-1] if(len(array)>0) else 1,n-sum(array)+1):
            for i2 in dfs(n,array+[i1]):
                result.append(i2)
        return result
#=================================================================================
def dfs(n,array=[]):
    if(n-sum(array)==0):return [array]
    else:return [i2 for i1 in range(array[-1] if(len(array)>0) else 1,n-sum(array)+1) for i2 in dfs(n,array+[i1])]
#=================================================================================
def dfs(n,array=[]):
    return [array] if(n-sum(array)==0) else [i2 for i1 in range(array[-1] if(len(array)>0) else 1,n-sum(array)+1) for i2 in dfs(n,array+[i1])]
#=================================================================================
dfs=lambda n,array=[]:[array] if(n-sum(array)==0) else [i2 for i1 in range(array[-1] if(len(array)>0) else 1,n-sum(array)+1) for i2 in dfs(n,array+[i1])]
"""
dfs=lambda n,array=[]:[array] if(n-sum(array)==0) else [i2 for i1 in range(array[-1] if(len(array)>0) else 1,n-sum(array)+1) for i2 in dfs(n,array+[i1])]
for i in dfs(20):print(i)
