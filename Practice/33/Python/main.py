_print = print

def create(size,first=0,step=0):
    a = []
    veil=first
    for i in range(size):
        if(i>0):
            veil=veil+step
            a.append(veil)
        else:
            a.append(first)
    return a
def sort(a):
        for i in range(1, len(a)):
            temp = a[i]
            j = i - 1
            while (j >= 0 and temp < a[j]):
                a[j + 1] = a[j]
                j = j - 1
                a[j + 1] = temp

        return a;
def print(a):
        _print(a)

size=int(input())
first=int(input())
step=int(input())

a=create(size,first,step)
sort(a)
print(a)