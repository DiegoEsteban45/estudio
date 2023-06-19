#include <stdlib.h>
#include <stdio.h>
#include "S6_TDALista_A1.h"
#define LARG 100
int main(int argc,  char *argv[]) {
	int promedio;
	Cola *cola;
	Listaa1 *lista1;
	Listaa1 *lista2;
	int A[LARG];
	printf("\n");
	lista1=a1crear_lista();
	a1insertar_nodo_ini(lista1, 2 ),a1insertar_nodo_ini(lista1, 7 ),a1insertar_nodo_ini(lista1, 6 ),a1insertar_nodo_ini(lista1, 3 );
	a1mostrar_lista(lista1);
	printf("\n");
	a1insertar_nodo_ini(lista1, 4 ),a1insertar_nodo_fin(lista1, 4 ),a1insertar_nodo_fin(lista1, 5 );
	a1mostrar_lista(lista1);
	printf("\n");
	printf("probelma 2\n");
	lista2=input_list();	
	promedio=calcular_promedio(lista2);
	a1mostrar_lista(lista2);
	printf("\nel promedio es:%d",promedio);
	printf("\n");
	return 0;
}





