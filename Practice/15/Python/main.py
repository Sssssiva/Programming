import random
g=1

while g==1:
    a=random.randint(0,100)
    print(a)
    b=int(input("Вводите число:\n"))
    i=1
    while i<5:
        i+=1
        if (b<a):
            print("Ваше число меньше")
            b=int(input())
        if (b > a):
            print("Ваше число больше")
            b = int(input())
        if(b==a):
            print("Вы выиграли!")
            break
    if(b!=a):
        print("Вы проиграли. Загаданное число " + str(a))
    g=int(input("Еслi хотите продолжить,введите 1: "))
