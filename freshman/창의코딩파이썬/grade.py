korea = int(input('국어점수 :'))
english = int(input('영어점수 :'))
math = int(input('수학점수 :'))

def grade(obj) :
    if obj >= 90 :
        return 'A'
    elif obj >= 80 :
        return 'B'
    elif obj >= 70 :
        return 'C'
    elif obj >= 60 :
        return 'D'
    else :
        return 'F'

print('국어 학점 :',grade(korea))
print('영어 학점 :',grade(english))
print('수학 학점 :',grade(math))
