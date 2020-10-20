print("Введите через пробел вещественное число, затем символ - знак операции и вещественное число")
x,sym,y=(map(str,input().split()))
if (sym != '+' and sym != '-' and sym != '*' and sym != '/'):
    print("Ошибка ввода действия. Ожидалось + - * / , а не "+ str(sym))
if(sym=="+"):
    print(float(x)+float(y))
elif (sym == "-"):
    print(float(x) - float(y))
elif (sym == "*"):
    print(float(x) * float(y))
elif (sym == "/"):
    print(float(x) / float(y))

