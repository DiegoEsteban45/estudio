from funciones import swap,entrada_0

#entrada
num=int
A=[] #ARRAY
print("escribe numeros + o -, y ctrl+z para finalizar:")
A=entrada_0(A,num)
i = 0
n=len(A)
print(A)  #lista de entrada
#proceso
while i < n:                         #lista intercalada[+, -, +, -, +, -, +, -, +, -, +, -,......]
    j = i + 1
    if j < n:                                                          
        if A[i] > 0:
            while j < n: 
                if A[j] < 0:
                    if j == i + 1:
                        i = i + 2
                        j = n
                    elif (j != i + 1):
                        swap(A ,j ,(i+1))
                        i = i + 2
                        j = n
                elif j == n-1:
                    i = n
                j = j + 1
        elif A[i] < 0:
            while j < n:
                if A[j] > 0:
                    swap(A ,j ,i)
                    if A[i+1]>0:
                       swap(A ,(i+1) ,j)
                    i = i + 2
                    j = n
                elif j == n-1:
                    i = n
                j = j + 1 
#salida            
print(A)  #lista de salida

