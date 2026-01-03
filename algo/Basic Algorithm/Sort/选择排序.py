while(1):
    number=input("Please enter list:")
    number=number.split(" ")
    for i in range (len(number)):
        for x in range (len(number)-i):
            if(number[1+i]<number[i]):
                t=number[i]
                number[i]=number[1+i]
                number[1+i]=t
    for s in number:
        print(s+" ",end="")
    print("")
