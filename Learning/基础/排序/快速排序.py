def qsort(array):
    if(len(array)==0):return []
    left=qsort([x for x in array[1:] if x<array[0]])
    right=qsort([x for x in array[1:] if x>=array[0]])
    return left+[array[0]]+right
