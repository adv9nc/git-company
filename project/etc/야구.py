
import random
import os


numbers = []

cnt_total = 0
cnt_strike = 0


rand_num = str(random.randint(0, 9))


for i in range(3):
    while rand_num in numbers:
        rand_num = str(random.randint(0, 9))
    numbers.append(rand_num)
os.system("cls")
print("=" * 50)
print("야구 게임을 시작합니다!!")
print("=" * 50)
while(cnt_strike < 3):
    cnt_strike = 0    
    cnt_ball = 0
    num = str(input("숫자 3자리를 입력하세요.> "))
    if len(num) == 3:
        for i in range(0, 3):
            for j in range(0, 3):
                if num[i] == numbers[j] and i == j:
                    cnt_strike += 1
                elif num[i] == numbers[j] and i != j:
                    cnt_ball += 1
        if cnt_strike == 0 and cnt_ball == 0:
            print("아웃!!")
        else:
            output = ""
          
            if cnt_strike > 0:
                output += "{} 스트라이크".format(cnt_strike)
            if cnt_ball > 0:
                output += " {} 볼".format(cnt_ball)
            print(output.strip())
        cnt_total += 1
print("*" * 50)
print("{} 회 만에 성공!!".format(cnt_total))
