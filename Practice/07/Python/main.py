import math
print("1 - ввод параметров треугольника через длины сторон\n2 - ввод параметров через координаты вершин")
o=int(input())
if(o==1):
    a=float(input("Введите сторону а: "))
    b=float(input("Введите сторону b: "))
    c=float(input("Введите сторону с: "))
    if ((a == 0 or b == 0 or c == 0) or (a + b < c or a + c < b or b + c < a)) :
        print("Введены неверные данные стороны а или стороны b или стороны c")
    p = 0.5 * (a + b + c)
    if (p * (p - a) * (p - b) * (p - c)):
        print("Отрицательный корень")
    S = math.sqrt(p * (p - a) * (p - b) * (p - c))
    print(S)
elif(o==2):
    x1,y1=map(float,input("Ввод первой точки: ").split())
    x2, y2 = map(float, input("Ввод второй точки: ").split())
    x3, y3 = map(float, input("Ввод третьей точки: ").split())
    if ((x1 == x2 and y1 == y2) or (x2 == x3 and y2 == y3) or (x1 == x3 and y1 == y3)):
        print("Неверные данные первой, второй или  точки")
    else:
        S= 0.5 * abs(((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)))
        print("S="+str(S))
else:
    print("Неверный ввод")