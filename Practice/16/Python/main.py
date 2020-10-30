a = 1
n = int(input("Введите количество билетов: "))
bul = ""
x = input("Введите билеты: ").split()
for i in range(len(x)):
    if ((x[i][0] == 'a') and (x[i][4] == '5') and (x[i][5] == '5') and (x[i][6] == '6') and (x[i][7] == '6') and (x[i][8] == '1')):
         b = x[i]
         bul += b + ' '
         a+=1
if (a==1):
    print(-1)
else: print(bul)


