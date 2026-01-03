def up(x):
    if(x==1):
        return
    if(heap[x]>heap[x//2]):
        heap[x],heap[x//2]=heap[x//2],heap[x]
        up(x//2)

def down(x):
    global tot
    if(x*2>tot):
        return
    son=x*2
    if(x*2+1<=tot and heap[x*2+1]>heap[x*2]):
        son+=1
    if(heap[son]>heap[x]):
        heap[x],heap[son]=heap[son],heap[x]
        down(son)

def add(x):
    global tot
    heap.append(x)
    tot+=1
    up(tot)

def pop():
    global tot
    heap[1]=heap[tot]
    heap.pop(tot)
    tot-=1
    down(1)

n=int(input())
tot=0
heap=[0]
for i in range(n):
    opt=input().split()
    if(opt[0]=='push'):
        x=int(opt[1])
        add(x)
    else:
        if(tot==0):
            print('empty')
        else:
            print(heap[1])
            pop()
