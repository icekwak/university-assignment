import random

print('홀/짝 게임!!!')

while True :
    number = random.randint(1,2)
    user = eval(input('\n(1 => 홀) | (2 => 짝) | (0 => 종료) :'))

    if user == 0 :
        print('\n종료')
        break;

    if user == 1 :
        print('\n홀 선택')
    else :
        print('\n짝 선택')

    if number == 1 :
        print('\n정답 : 홀')
    else :
        print('\n정답 : 짝')

    if number == user :
        print('\n맞춤!!!')
    else :
        print('\n틀림...')

    print('='*40)
