print("Введите через пробел число и степень в которую его нужно возвести")
a,b=(map(int,input().split()))
i=1
x=a
while (i<b):
    i+=1
    a*=x
if (b>0):
    print(a)
elif(b<0):
    print(1/a)
elif(b==0):
    print("1")
