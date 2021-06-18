while True :
    dan_num = int(input('몇 단을 계산할까요? (0: 종료) '))

    if dan_num == 0 :
        print('이용해 주셔서 감사합니다.')
        break;

    print('\n {} 단은 바로..\n'.format(dan_num))
    print('='*15)
    for cnt in range(9) :
        result = dan_num * (cnt+1)
        print('{0:2} * {1:1} = {2:4}'.format(dan_num,cnt+1,result))
    print('='*15)
