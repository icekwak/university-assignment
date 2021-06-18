import random

cnt = int(input('숫자 맞추기 게임을 몇 번 하시겠습니까? '))
print('총 [ {} ] 번 게임을 시작하겠습니다. (한 게임당 제한횟수 : 3번)'.format(cnt))
print('(단, 입력할 수 있는 숫자는 1 ~ 5)')
print('제한횟수 안에 꼭 맞추세요.')

i = 0
win = 0
lose = 0
while i < cnt :
    print('[ {} ]번째 게임'.format(i+1))

    j = 0
    suc = 0
    fail = 0
    while j < 3 :
        number = int(input('\n숫자 입력 :'))
        com_number = random.randint(1,5)

        if number == com_number :
            print('[ 맞춤!!! ]')
            suc += 1
        else :
            print('[ 틀림... ]')
            fail += 1
        j += 1

    if suc > 0 and lose >= 0:
        print('[ {} ]번째 게임 성공!!!'.format(i+1))
        win += 1
    elif suc == 0 and lose >= 0 :
        print('[ {} ]번째 게임 실패...'.format(i+1))
        lose += 1

    print('='*25)
    i += 1

print('\n성공[ {} ] , 실패[ {} ]'.format(win,lose))
