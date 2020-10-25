import math
n=int(input("Введите целое число"))
i=0
k=0
while (2**i) <= n:
    i+=1
    k+=1
print(k)
