
# 두 수를 입력 받으면 사칙연산을 수행하는 프로그램을 제작

def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y
# asdfasdf

def divide(x, y):
    if y == 0:
        return "0으로 나눌 수 없습니다."
    else:
        return x / y

print("사칙연산 프로그램을 시작합니다.")
n1 = float(input("첫 번째 숫자를 입력해주세요: "))
n2= float(input("두 번째 숫자를 입력해주세요: "))

print("두 수의 합:", add(n1, n2))
print("두 수의 차:", subtract(n1, n2))
print("두 수의 곱:", multiply(n1, n2))
print("두 수를 나눈 값:", divide(n1, n2))