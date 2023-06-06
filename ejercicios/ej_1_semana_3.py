from funciones import swap

A=[2,10,17,23,15,16,3,10,8]
mitad=4
i=0
c=mitad+1
n=(len(A)-1)
print(A)
while i<mitad and c<n:
      swap(A,i,mitad)
      print('PRIMERA',A)
      swap(A,c,n)
      print('SEGUNDA',A)
      i=i+1
      n=n-1
      mitad=mitad-1
      c=c+1
      
