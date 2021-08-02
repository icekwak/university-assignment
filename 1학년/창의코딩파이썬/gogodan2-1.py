print('구구단표')

print('   |',end='\t')
for i in range(9) :
    print('{0:2}'.format(i+1),end='\t')
print('-'*76)

for i in range(9) :
    print('{}  |'.format(i+1),end='\t')
    for j in range(9) :
        result = (i+1) * (j+1)
        print('{0:2}'.format(result),end='\t')
