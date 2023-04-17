from funciones import swap,valor_minimo,entrada,valor_minimo_smart
#INPUT
A=[]
print('Enter numbers and press enter to input the next number, and enter ctrl z to finish')
F=int(input('write a number,:'))
A.append(F)
A=entrada(A,F)
#PROCESS 
i=0 
aum=0
lEN=len(A) 
for i in range(i,lEN-1,1): 
    print('List sorted from lowest to highest',A)
    min_indice=valor_minimo_smart(A,lEN,aum)
    if min_indice != aum:     
       swap(A,min_indice,i)
    elif min_indice == -1:
        break
    aum=aum+1   
#OUTPUT  
