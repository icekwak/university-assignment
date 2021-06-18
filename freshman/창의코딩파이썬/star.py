h = int(input('피라미드 높이 입력 :'))

for i in range(h) :
    print(' '*(h-(i+1)),'*'*(i*2+1))
