flipper="1234"
exchange=input()
for i in exchange:
    if(i=="H"):
        flipper=flipper[2]+flipper[3]+flipper[0]+flipper[1]
    if(i=="V"):
        flipper=flipper[1]+flipper[0]+flipper[3]+flipper[2]
print(flipper[0]+" "+flipper[1])
print(flipper[2]+" "+flipper[3])
