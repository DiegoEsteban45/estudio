#ejercicio 2 de la semana 3
from funciones import swap

A=[2,10,17,23,15,16,3,10,8]
mitad=4
c=mitad+1
i=1
print(A)
for i in range(i,(len(A)-1),2):
    j=i
    print(j)
    k=c
    print(k)
    print(c)
    while j<k:
          swap(A,k,k-1)
          k=k-1
          print(A)  
    c=c+1








