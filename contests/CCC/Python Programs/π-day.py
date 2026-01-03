list = []
n = int(input())
k = int(input())
for i in range(k - 1):
    list.append(1)
list.append(n - k + 1)
m = k - 2
result = 1
while(abs(list[k - 1] - list[0]) >= 2):
    list[list.index(list[k - 1])] = list[list.index(list[k - 1])] - 1
    list[m] = list[m] + 1
    result = result + 1
    if(abs(list[k - 1]-list[m]) < 2):
        m = m - 1
print(result)
