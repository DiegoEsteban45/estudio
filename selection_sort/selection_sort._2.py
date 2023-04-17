from funciones import swap,valor_minimo,entrada,valor_minimo_smart
#INPUT
A=[]
print('Enter numbers and press enter to input the next number, and enter ctrl z to finish')
F=int(input('write a number,:'))
A.append(F)
A=entrada(A,F)
#PROCESS 
i=0 
lEN=len(A) 
while i<=lEN: 
    print('List sorted from lowest to highet',A)
    min_indice,i=valor_minimo_smart(A,lEN,i)
    print(i,min_indice)
    if min_indice!=i:     
        swap(A,min_indice,i)
    elif min_indice==-1 and i==-1:
        i=lEN+1
    i=+i  
#OUTPUT  
