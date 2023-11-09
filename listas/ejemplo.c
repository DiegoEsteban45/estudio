#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>
#include "TDA_L_P_C.h"

void eliminar_elementos_menores(lista *l, int limite){
    if (!lista_vacia(l)&&(l->n>1)){
        nodo *aux2  =l->cabeza;
        nodo *aux2_0=aux2->siguiente;
        nodo *aux2_1=aux2_0->siguiente;
        nodo *ante_penultimo;
        while((l->cabeza->info < limite)&&(!lista_vacia(l))){
            aux2=l->cabeza;
            l->cabeza=l->cabeza->siguiente;
            free(aux2);
            l->n--;
            nodo *aux2;
            mostrar_lista(l);
        } 
        aux2=l->cabeza;
        ante_penultimo=aux2;
        aux2_0=aux2->siguiente;
        aux2_1=aux2_0->siguiente;
        while ((aux2_1!=NULL)){
            if (aux2_0->info<limite){   
                free(aux2->siguiente);
                aux2->siguiente=aux2_1;
                l->n--;
                ante_penultimo=aux2;
                aux2_0=aux2_1;
                aux2_1=aux2_0->siguiente;
            }else{
                aux2=aux2->siguiente;
                ante_penultimo=aux2;
                aux2_0=aux2->siguiente;
                aux2_1=aux2_0->siguiente;    
            }  
        }
        if (aux2_0->info<limite){
            free(ante_penultimo->siguiente);
            ante_penultimo->siguiente=NULL;
        }
    }else if(l->cabeza->info<limite){
            eliminar_nodo_ini(l);
    }
}
