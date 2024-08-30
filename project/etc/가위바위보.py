import random

rsp=['주먹','가위','보']
computer_pick=random.choice(rsp)
player_pick=input('주먹, 가위, 보중 하나를 고르세요.')

if computer_pick==player_pick:
         print('비겼습니다')
elif (computer_pick == '가위' and player_pick == '주먹') or (computer_pick == '주먹' and player_pick == '보') or (computer_pick == '보' and player_pick == '가위'):
         print('이겼습니다.')
else:
         print('졌습니다')
