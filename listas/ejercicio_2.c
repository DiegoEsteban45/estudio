#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>
#include "TDA_L_P_C.h"

/*Dadas dos listas L1 y L2, construya un algoritmo en pseudocódigo que entregue la
cantidad de veces que cada elemento en L1 se encuentra en L2.*/
int main(int argc, char const *argv[]){
    lista *l_2;
    lista *l_1;
    nodo *aux;
    int mid,lim_inf,lim_sup,cont;
    int *A,*B;
    printf("lista 1\n");
    l_1=input_list();
    printf("lista 2\n");
    l_2=input_list();
    A=crear_array(l_1->n+1);
    obtener_elementos(l_1,A);
    shellshort(A,l_1->n);
    aux=l_2->cabeza;
    lim_inf=0;
    lim_sup=l_1->n;
    cont=0;
    printf("elementos repetidos->(");
    while (aux!=NULL){    
          if (binarisearchr(aux->info,A,lim_inf,lim_sup,mid)){
                cont++;
                printf(" %d ",aux->info);
                aux=aux->siguiente;
          }else{
                aux=aux->siguiente;
          }
    }
    printf(")");
    imprimir(A);
    printf("\n\nl1");
    mostrar_lista(l_1);
    printf("\n\nl2");
    mostrar_lista(l_2);
    printf("\nlos elementos de l1 se repiten %d en l2\n",cont);

    return 0;
}

