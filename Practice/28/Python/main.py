def delimosti(n,number):#Проверка делимости на текущий множитель number
		if ((n%number == 0) and (n>1)):
			return 1
		else:
			return 0

def print_factorization(n: int) ->None:
	delaem = True
	number = 2
	while(delaem == True):#делаем покм n>1
		count = 0
		proverka = delimosti(n, number)#проверяем делимость текущего n и текущего множителя
		while(proverka):# если делится,то
			count +=1
			n = n/number # делим на множитель, чтобы проверять кол-во сомножителей
			proverka = delimosti(n, number)# проверяем
		if (count > 0):# вывод в консоль
			print(number, end="")
			if (count > 1):#если больше одного сомножителя имеется
				print('^',count, end="", sep="")
			if (n>1):
				print('*', end="")
		number+=1
		if(n<=1):
			delaem = False

n = int(input())
if(n<2):
	print("1")
print_factorization(n)