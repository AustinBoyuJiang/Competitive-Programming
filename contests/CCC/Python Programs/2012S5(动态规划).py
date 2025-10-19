R,C = input().split() #rows, columns (1,1 in upper left then increasing while going down and right)
R = int(R)
C = int(C)

cats = []
lab = []
K = int(input()) #number of cats

for i in range(R+1):
  row = []
  cat = []
  for j in range(C+1):
    row.append(0)
    cat.append(True)
  lab.append(row)
  cats.append(cat)

for i in range(K):
  r,c = input().split()
  c = int(c)
  r = int(r)
  lab[r][c] = 0
  cats[r][c] = False
  
lab[1][1] = 1
cats[1][1] = False

for i in range(1,R+1):
  for j in range(1,C+1):
    if cats[i][j] == True:
      lab[i][j] = lab[i-1][j] + lab[i][j-1]
      
print (lab[R][C])
