print('\t'*2,'구구단표')

print('  |',end='   ')
for cnt in range(9) :
    print((cnt+1),end='   ')
print(end='\n'+'-'*41)

for i in range(9) :
    print(end='\n'+'{} |'.format(i+1))
    for j in range(9) :
        result = (i+1) * (j+1)
        print(end='  '+'{0:2}'.format(result))

