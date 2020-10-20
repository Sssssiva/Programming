import math
a=int(input("Введите чему равно а: "))
b=int(input("Введите чему равно b: "))
c=int(input("Введите чему равно c: "))
if (a==0 and b!=0 and c!=0):
    print("x= " +str(-c/(b)))
elif (a!=0 and b!=0 and c!=0):
    d= (b**2) - 4 * a * c
    if (d>0):
        print("x1= "+str((-b+math.sqrt(d))/(2*a))+"\tx2= "+str((-b-math.sqrt(d))/(2*a)))
    if(d<0):
        print("Решений нет")
    if (d==0):
        print("x= "+str(-b/(2*a)))
elif (c==0 and b!=0 and a!=0):
    print("x1=0"+"\tx2="+str(b/a))
elif(a==0 and b==0 and c==0):
    print("Множество корней")