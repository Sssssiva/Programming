print("Введите s, l1, r1, l2, r2: ")
s,l1,r1,l2,r2=(map(int,input().split()))
if ((l1 >= r1) or (l2 >= r2)):
    print("Неправильный ввод")
elif ((l1 + l2) > s or ((r1 + r2) < s)):
    print("-1")
elif ((l1 + r2)-s== 0):
    print("x1=" + str(l1) + " x2=" + str(r2))
elif ((l1 + r2) - s > 0):
    print("x1=" +str(l1) + " x2="+ str(r2 - ((r2 + l1)-s)))

elif ((l1 + r2) - s < 0):
    print("x1="+str( l1) - ((l1 + r2) - s)+ " x2=" << str(r2))
