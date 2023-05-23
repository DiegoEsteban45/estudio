#include <string.h>
#include <stdio.h>

main(){
    int A[100];
    memset(A, 0, sizeof(A));  // Inicializa todos los elementos del arreglo a cero
}

int imprimir(int *array){
    while (*array!=-1){
           printf("%d,",*array);
           array++;
        }
}
