import math
import random
def Bozosort1(data,info=True):
    sost=False
    while(sost==False):
        x1=random.randint(0,len(data)-1)
        x2=random.randint(0,len(data)-1)
        swap=data[x1]
        data[x1]=data[x2]
        data[x2]=swap
        sost=True
        if(info==True):
            for i in range(1,len(data)):
                if (data[i-1]>data[i]):
                    sost=False
                    break
        else:
            for i in range(1,len(data)):
                if (data[i-1]<data[i]):
                    sost=False
                    break
    return data
def Bozosort2(data,info=True):
    dop_massive=[]
    for i in range(len(data)):
        for j in range(len(data)):
            dop_massive.append(data[i][j])
    return Bozosort1(dop_massive,info)
def Bozosort3(a,b,c,info=True):
    dop_massive3=[]
    dop_massive3.append(a)
    dop_massive3.append(b)
    dop_massive3.append(c)
    return Bozosort1(dop_massive3,info)
n=int(input())
data=list()
for i in range(n):
    data.append(int(input()))
output=Bozosort1(data)
for i in range(len(data)):
    print(output[i],end=" ")
print()
output=Bozosort1(data,info=False)
for i in range(len(data)):
    print(output[i],end=" ")
data2=[]
check=0
print()
for i in range(int(math.sqrt(n))):
    dop_massive2=[]
    for j in range(int(math.sqrt(n))):
        dop_massive2.append(data[check])
        check=check+1
    data2.append(dop_massive2)
    if (check>len(data)):
        break
output=Bozosort2(data2)
for i in range(len(output)):
    print(output[i],end=" ")
print()
output=Bozosort2(data2,False)
for i in range(len(output)):
    print(output[i],end=" ")
print()
a=data[0]
b=data[1]
c=data[2]
output=Bozosort3(a,b,c)
for i in range(len(output)):
    print(output[i],end=" ")
print()
output=Bozosort3(a,b,c,False)
for i in range(len(output)):
    print(output[i],end=" ")
print()