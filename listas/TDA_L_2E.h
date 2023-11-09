#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>

typedef struct nodo_doble {
    struct nodo_doble* anterior;
    struct nodo_doble* siguiente;
    int info;
} nodo_doble;

typedef struct lista_doble {
    nodo_doble* cabeza;
    int n;
} lista_doble;

lista_doble *crear_lista_doble();
nodo_doble *crear_nodo_doble(int num);
bool lista_doble_vacia(lista_doble *l);
void insertar_nodo_doble_ini(lista_doble *l,int num);
void insertar_nodo_doble_fin(lista_doble *l,int num);
lista_doble *input_list_doble();
void mostrar_lista_doble(lista_doble *L1);
void eliminar_nodo_doble(lista_doble *l,int num);

lista_doble* crear_lista_doble() {
    lista_doble* l_d = (lista_doble*)malloc(sizeof(lista_doble));
    l_d->cabeza = NULL;
    l_d->n = 0;
    return l_d;
}

nodo_doble* crear_nodo_doble(int num) {
    nodo_doble* new = (nodo_doble*)malloc(sizeof(nodo_doble));
    new->anterior = NULL;
    new->siguiente = NULL;
    new->info = num;
    return new;
}

bool lista_doble_vacia(lista_doble *l){
    if(l->cabeza==NULL){
        return true;
    }else{
        return false;
    }
}
void insertar_nodo_doble_ini(lista_doble *l,int num){
    nodo_doble *aux,*new_nodo;
    aux=l->cabeza;
    if(!lista_doble_vacia(l)){
        new_nodo=crear_nodo_doble(num);
        aux->anterior=new_nodo;
        new_nodo->siguiente=aux;
    }else{
        new_nodo=crear_nodo_doble(num);
    }
    l->cabeza=new_nodo;
    l->n++;
}
void insertar_nodo_doble_fin(lista_doble *l,int num){
    nodo_doble *aux,*new_nodo;
    aux=l->cabeza;
    if (!lista_doble_vacia(l)){
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        new_nodo=crear_nodo_doble(num);
        aux->siguiente=new_nodo;
        new_nodo->anterior=aux;
    }else{
        new_nodo=crear_nodo_doble(num);
        l->cabeza=new_nodo;
    }
    l->n++;
}

lista_doble* input_list_doble() {
    int num, num_2;
    lista_doble* lista;
    lista = crear_lista_doble();
    num = 0;

    printf("Ingresar numeros, escriba -1 para finalizar\n");
    scanf("%d", &num_2);

    if (num_2 != -1) {
        insertar_nodo_doble_ini(lista, num_2);

        while (num_2 != -1) {
            printf("Ingresar numeros, escriba -1 para finalizar\n");
            scanf("%d", &num_2);

            if (num_2 != -1) {
                insertar_nodo_doble_fin(lista, num_2);
            }
        }
    }
    return lista;
}

void mostrar_lista_doble(lista_doble* L1) {
    nodo_doble* aux;

    if (!lista_doble_vacia(L1)) {
        printf("\nCantidad de elementos: %d\n", L1->n);
        aux = L1->cabeza;
        printf("L->");

        while (aux != NULL) {
            printf(" %d", aux->info);
            aux = aux->siguiente;
        }
    } else {
        printf("Lista vacía");
    }
}

void eliminar_nodo_doble(lista_doble* l, int num) {
    nodo_doble* aux = l->cabeza;
    nodo_doble* aux_null = crear_nodo_doble(0); // Crear un nodo nulo auxiliar

    while (aux != NULL) {
        if (num == aux->info) {
            if (aux == l->cabeza) {
                // Eliminar el nodo en la cabeza de la lista
                l->cabeza = aux->siguiente;
                if (l->cabeza != NULL) {
                    l->cabeza->anterior = NULL;
                }
                l->n--;
                free(aux);
                aux = aux_null->siguiente;
            } else {
                if (aux->siguiente == NULL) {
                    // Eliminar el nodo en la cola de la lista
                    aux->anterior->siguiente = NULL;
                } else {
                    // Eliminar un nodo en el medio de la lista
                    aux->anterior->siguiente = aux->siguiente;
                    aux->siguiente->anterior = aux->anterior;
                }
                l->n--;
                free(aux);
                aux = aux_null->siguiente;
            }
        } else {
            aux = aux->siguiente;
        }
    }

    free(aux_null); // Liberar el nodo nulo auxiliar
}

