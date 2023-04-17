from funciones import swap,valor_minimo,entrada
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
    min_indice=valor_minimo(A,lEN,aum) 
    if min_indice != aum:    
       swap(A,min_indice,i)      
    aum=aum+1
#OUTPUT  
print('List sorted from lowest to highest',A)