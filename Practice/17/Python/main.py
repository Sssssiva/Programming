a=[0]*37
b=[0]*37
red,black,c,i=0,0,0,0
while(1):
    n=int(input())
    if(n<0):
        exit(1)
    a[n]+=1
    b[n]+=1
    for i in range(37):
        if (a[i]>c):
            c=a[i]
    for i in range(37):
        if (a[i]==c):
            print(str(i),end=" ")
    print("")
    for i in range(37):
        if(b[i]==0):
            print(str(i),end=" ")
    print("")
    if(n == 1 or n == 3 or n == 5 or n == 7 or n == 9 or n == 12 or n == 14 or n == 16 or n == 18 or n == 19 or n == 21 or n == 23 or n == 25 or n == 27 or n == 30 or n == 32 or n == 34 or n == 36):
        red+=1
    else:
        black+=1
    print(str(red) + " " + str(black))
    print("")