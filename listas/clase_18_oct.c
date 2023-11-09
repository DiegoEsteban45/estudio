#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>
#include "TDA_L_P_C.h"


lista *reordenar(lista *L){
    lista *L_mod = crear_lista();
    nodo *aux=L->cabeza;
    int cont=1;
    while (aux!=NULL){
        if(aux->siguiente==NULL){
            insertar_nodo_ini(L_mod,aux->info);
            return L_mod;
        }
        if(cont%2!=0){
            insertar_nodo_ini(L_mod,aux->info);
        }else{
            insertar_nodo_fin(L_mod,aux->info);
        }
        cont++;
        aux=aux->siguiente;  
    } 
}

int main(int argc, char const *argv[]){

    printf("\n\n ejercicio 1\n");
    //(1)
    lista *lista1,*lista1_mod;
    lista1=input_list();
    lista1_mod=reordenar(lista1);
    mostrar_lista(lista1_mod);
    invertir_lista(lista1_mod);
    mostrar_lista(lista1_mod);
    vaciar_lista(lista1_mod);
    mostrar_lista(lista1_mod);
   
   

    printf("\n\n ejercicio 2\n");
    //(2)

    lista *l_2 = input_list();
    nodo *aux0 = l_2->cabeza;
    printf("\nlista 2\n");
    mostrar_lista(l_2);
    while(aux0!=NULL){
        if (aux0->info%2==0){
            aux0->info=(aux0->info)*3; 
        }
        aux0=aux0->siguiente;
    }
    printf("\nnlista 2 modificada\n");
    mostrar_lista(l_2);

    printf("\n\n ejercicio 3\n");
    //(3)

    lista *l_3,*l_3r;
    nodo *aux1;
    l_3r=crear_lista();
    l_3=input_list();
    aux1=l_3->cabeza;
    while (aux1!=NULL){
        if(aux1->info%2!=0){
            if (lista_vacia(l_3r)){
                insertar_nodo_ini(l_3r,aux1->info);
            }else{
                insertar_nodo_fin(l_3r,aux1->info);
            }      
        }
        aux1=aux1->siguiente;
    }
    mostrar_lista(l_3);
    mostrar_lista(l_3r);
    
    printf("\n\n ejercicio 4");
    //(4)
    lista *l_4;
    int num;
    printf("escriba un numero: ");
    scanf("%d",&num);
    l_4=input_list();
    mostrar_lista(l_4);
    eliminar_elementos_menores(l_4,num);
    mostrar_lista(l_4);
}

