number="0000"
x=str(input())
number=x+number[1]+number[2]+number[3]
x=str(input())
number=number[0]+x+number[2]+number[3]
x=str(input())
number=number[0]+number[1]+x+number[3]
x=str(input())
number=number[0]+number[1]+number[2]+x
if((int(number[0])==8 or int(number[0])==9) and (int(number[3])==8 or int(number[3])==9) and (number[1]==number[2])):
    print("ignore")
else:
    print("answer")
