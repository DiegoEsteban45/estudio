#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDA_L_2E.h"

int main(int argc, char const* argv[]) {
    lista_doble* l;
    l = input_list_doble();
    mostrar_lista_doble(l);

    // Eliminar elementos duplicados
    nodo_doble* aux = l->cabeza;

    while (aux != NULL) {
        nodo_doble* actual = aux->siguiente;

        while (actual != NULL) {
            if (aux->info == actual->info) {
                nodo_doble* temporal = actual;//creamos un nodo temporal para ser eliminado y acomodamos los nodos
                actual = actual->siguiente;
                temporal->anterior->siguiente = actual;
                if (actual != NULL) {
                    actual->anterior = temporal->anterior;
                }
                free(temporal);
                l->n--;
            } else {
                actual = actual->siguiente;
            }
        }

        aux = aux->siguiente;
    }
    mostrar_lista_doble(l);

    return 0;
}


