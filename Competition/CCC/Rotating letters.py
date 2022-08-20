yes=["I","O","S","H","Z","X","N"]
s = str(input())
for i in range (len(s)):
    if(not(s[i] in yes)):
        print("NO")
        break
    if(i==len(s)-1):
        print("YES")
