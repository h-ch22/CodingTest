import sys

weight = float(sys.stdin.readline().rstrip())
tall = float(sys.stdin.readline().rstrip())

bmi = weight / (tall ** 2)

if bmi > 25:
    print("Overweight")

elif 18.5 < bmi < 25.0:
    print("Normal weight")

else:
    print('Underweight')
