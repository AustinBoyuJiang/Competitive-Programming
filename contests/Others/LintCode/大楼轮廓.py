class Solution:
    def buildingOutline(self,buildings):
        answer=[]
        result=[]
        x,y=0,0
        last=0
        for i in range(len(buildings)):
            x=max(x,buildings[i][1])
            y=max(y,buildings[i][2])
        Map=[[0 for j in range(y+2)] for i in range(x+2)]
        for i in range(len(buildings)):
            Map[buildings[i][0]+1][1]+=1
            Map[buildings[i][1]+1][1]-=1
            Map[buildings[i][0]+1][buildings[i][2]+1]-=1
            Map[buildings[i][1]+1][buildings[i][2]+1]+=1
        for i in range(1,x+2):
            for j in range(1,y+2):
                Map[i][j]=Map[i][j]+Map[i-1][j]+Map[i][j-1]-Map[i-1][j-1]
        for i in range(1,x+2):
            for j in range(y+1,-1,-1):
                if(Map[i][j]!=0 or j==0):
                    if(j!=last):
                        if(last!=0):result+=[[i-1,last]]
                        if(j!=0):result+=[[i-1,j]]
                    last=j
                    break
        for i in range(0,len(result),2):
            answer+=[[result[i][0],result[i+1][0],result[i][1]]]
        return answer
a=Solution()
s=[
    [1, 3, 3],
    [2, 4, 4],
    [5, 6, 1]
]
print(a.buildingOutline(s))
