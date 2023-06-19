#include <stdlib.h>
#include <stdio.h>
#include "S6_TDALista_A1.h"
int main(int argc,  char *argv[]){
//inicializacion
    Listaa1 *lista2 ,*lista1;
    int *A;
//entradas
    printf("lista 1 ingrese valores\n");
    lista1 = input_list();
    printf("lista 2 ingrese valores\n");
    lista2 = input_list();
//proceso
    if((!(a1is_lista_vacia(lista1)))&&(!(a1is_lista_vacia(lista2)))){
        printf("lista 1 ");
        a1mostrar_lista(lista1);
        repetir_elementos(lista1 ,lista2); //repite los elementos de la lista 1 que estan tambien en la lista 2
        A = crear_array(lista2->n+1);
        obtener_elementos(lista2 ,A);
        shellshort(A,lista2->n);
//salidas
        printf("\n\n");
        printf("lista 2");
        a1mostrar_lista(lista2);
        printf("\n\n");
        printf("lista modificada");
        a1mostrar_lista(lista1);
        printf("\n");
        imprimir(A);
    }else{
        if(1==(a1is_lista_vacia(lista1))){
              printf("\nERROR LISTA 1 VACIA\n"); 
        }
        if(1==(a1is_lista_vacia(lista2))){
              printf("\nERROR LISTA 2 VACIA\n"); 
        }
    }
    free(lista1);
    free(lista2);
    free(A);
    return 0;   
}
