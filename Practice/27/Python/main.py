import math
import random
def Bozosort1(data):
    sost=False
    while(sost==False):
        x1=random.randint(0,len(data)-1)
        x2=random.randint(0,len(data)-1)
        swap=data[x1]
        data[x1]=data[x2]
        data[x2]=swap
        sost=True
        for i in range(1,len(data)):
            if (data[i-1]<data[i]):
                sost=False
                break
    return data
def inputing(output,index,count):
    for index in range(index,len(output)):
        print(output[index],end=" ")
    print()
n=int(input())
index=0
count=0
data=[]
end=list((map(int,input().split())))
for i in range(n):
    data.append(end[count])
    count+=1
    if(count<6):
        output=Bozosort1(data)
        inputing(output,index,count)
    else:
        index=count-5
        output = Bozosort1(data)
        inputing(output, index, count)
