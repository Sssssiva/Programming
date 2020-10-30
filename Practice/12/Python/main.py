print("Введите число для дальнейшего расчета факториала: ")
a=int(input())
if (a<=0):
    print("Error")
    exit(1)
b=1
for i in range(1,a+1):
    b*=i
print(b)