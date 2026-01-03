def qsort(arr):
    if not len(arr):return []
    else:
        pivot = arr[0]
        left = qsort([x for x in arr[1:] if x < pivot])
        right = qsort([x for x in arr[1:] if x >= pivot])
    return left+[pivot]+right

a = int(input())
b = int(input())
c = []
d = 0
for i in range(b):c.append(int(input()))
for i in qsort(c):
    if(a >= i):
        a = a-i
        d = d+1
    else:break
print(d)
