class permutation():
    visit1=[]
    visit2=[]
    List=None
    length=None
    repeat=None
    def dfs(This,n):
        if(n>=permutation.length):
            if(This==[] or This in permutation.visit2):
                return[]
            else:
                permutation.visit2+=[This]
                return [This]
        result=[]
        for i in range (len(permutation.List)):
            if(permutation.repeat):
                result+=permutation.dfs(This+[permutation.List[i]],n+1)
            else:
                if(not(i in permutation.visit1)):
                    permutation.visit1+=[i]
                    result+=permutation.dfs(This+[permutation.List[i]],n+1)
                    permutation.visit1.remove(i)
        return result
    def arrange(self,List,repeat=True,length=None):
        permutation.List=List
        if(length==None):permutation.length=len(permutation.List)
        else:permutation.length=length
        permutation.repeat=repeat
        return permutation.dfs([],0)
