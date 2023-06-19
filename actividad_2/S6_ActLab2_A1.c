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
/*
//(11)
int calcular_promedio(Listaa1 *lista){ /*calcula el promedio de elementos de la lista*/
	int num;
	int suma;
	int promedio;
	int nodo;
	Nodoa1 *aux;
	suma = 0;
	aux = lista->heada1;
	while(aux != NULL){
		 nodo=aux->infoa1;
		 suma=nodo+suma;
		 aux = aux->siga1;	
	}
	promedio=suma/(lista->n);
	return promedio;	
}
//(12)
Listaa1 *input_list(){ /* crea una lista por entrada*/
	int num;
	int num_2;
	Listaa1 *lista;
	lista = a1crear_lista();
	num = 0;
	printf("ingresar numeros, escriba -1 para finalizar\n");
	scanf("%d", &num_2);
	if(num_2 != -1){
		a1insertar_nodo_ini(lista, num_2);
		while(num != -1){
			printf("ingresar numeros, escriba -1 para finalizar\n");
			scanf("%d",&num);
			if (num != -1){
				a1insertar_nodo_fin(lista, num);
			}
		}				
	}
	return lista; 
}
*/




