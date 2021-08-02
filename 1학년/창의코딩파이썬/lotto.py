import random

while True :
    print('-'*80)
    print('!!! lotto !!!')
    print('[ 1부터 45까지 6개의 숫자를 골라 입력하시오. ]')
    print('( 단, 숫자 중복불가 )')
    print('\n')

    choice_bonus_number = random.randint(0,5)
    list_lotto_number = random.sample(range(1,45),7)
    list_bonus_number = [list_lotto_number.pop(choice_bonus_number)]
    list_lotto_number.sort()

    print('종료 -> [ 0 ] 입력')
    print('직접 숫자 입력(수동) -> [ 1 ] 입력')
    print('자동 숫자 입력 -> [ 2 ] 입력')
    choice = int(input('선택: '))
    print('-'*80)

    if choice == 1 :
        list_user_number = []
        while True :
            print('\n')
            user_number = int(input('숫자 입력: '))
        
            for i in range(len(list_user_number)) :
                number = list_user_number[i]
                if number == user_number :
                    print('[ *중복* 다시 입력하시오. ]')
                    list_user_number.remove(user_number)
                    break;
            
            if 0 >= user_number or user_number >= 46 :
                print('[ *없는 숫자* 다시 입력하시오. ]')
            else :
                list_user_number.append(user_number)

            if len(list_user_number) == 6 :
                break;

    elif choice == 2 :
        list_user_number = random.sample(range(1,45),6)

    else :
        print('종료')
        break;

    list_user_number.sort()

    print('\n')
    print('입력번호= ',list_user_number)
    print('로또번호= ',list_lotto_number,' 보너스번호=',list_bonus_number)
    print('\n')

    agree_lotto = 0
    for i in range(len(list_user_number)) :
        for j in range(len(list_lotto_number)) :
            if list_user_number[i] == list_lotto_number[j] :
                agree_lotto += 1


    agree_bonus = 0
    for i in range(len(list_bonus_number)) :
        for j in range(len(list_user_number)) :
            if list_bonus_number[i] == list_user_number[j] :
                agree_bonus += 1

    print('맞은 수= [ {} ]'.format(agree_lotto),'  보너스 맞은 수= [ {} ] '.format(agree_bonus))
    print('\n')

    if agree_lotto < 3 :
        print('꽝')
    elif agree_lotto == 3 :
        print('5등')
    elif agree_lotto == 4 :
        print('4등')
    elif agree_lotto == 5 :
        print('3등')
    elif agree_lotto == 5 and agree_bonus == 1 :
        print('2등')
    elif agree_lotto == 6 :
        print('1등')
