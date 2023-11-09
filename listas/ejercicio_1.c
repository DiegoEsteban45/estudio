#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>
#include "TDA_L_P_C.h"


int main(int argc, char const *argv[]){
/*ejercicio 1 guia:Dada una lista simplemente enlazada L, construya un algoritmo en pseudocódigo
que invierta el orden de los elementos de la lista.*/
lista *l_1,*l_1inv;
nodo *aux;
l_1=input_list();
l_1inv=crear_lista();
aux=l_1->cabeza;
mostrar_lista(l_1);
while(aux!=NULL){
      insertar_nodo_ini(l_1inv,aux->info);
      aux=aux->siguiente;
}
printf("\nnlista invertida\n");
mostrar_lista(l_1inv);
    return 0;
}
