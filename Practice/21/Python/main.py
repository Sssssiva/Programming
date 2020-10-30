def bmi(weight:float,height:float):
    return float(weight/((height/100)**2))

def print_bmi(bmi:float):
    if (bmi<18.5):
        print("Underweight")
    elif(bmi>=18.5 and bmi<25.0):
        print("Normal")
    elif (bmi >= 25.0 and bmi < 30.0):
        print("Overweight")
    elif (bmi >= 30.0):
        print("Obesity")
weight, height = map(float, input().split())
print_bmi(bmi(weight,height))