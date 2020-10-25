a=int(input("Введите число: "))
if(a>1):
    if (a == 5 or a == 2 or a == 3):
        print(str(a) + "-простое")
    elif (a % 2 != 0 and a % 3 != 0 and a % 5 != 0):
        print(str(a) + "-простое")
    elif (a % 2 == 0 or a % 3 == 0 or a % 5 == 0):
        print(str(a)+ "-составное")
else:
    print("Неправильный ввод")
