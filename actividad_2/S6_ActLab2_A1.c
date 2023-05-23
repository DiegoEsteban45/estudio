#include <stdlib.h>
#include <stdio.h>
#include "S6_TDALista_A1.h"
int main(int argc,  char *argv[]) {
	int promedio;
	Listaa1 *lista1;
	printf("\n");
	lista1=a1crear_lista();
	a1insertar_nodo_ini(lista1, 2 );
	a1insertar_nodo_ini(lista1, 7 );
	a1insertar_nodo_ini(lista1, 6 );
	a1insertar_nodo_ini(lista1, 3 ); 
	a1mostrar_lista(lista1);
	printf("\n");
	a1insertar_nodo_ini(lista1,  4 ); 
	a1insertar_nodo_fin(lista1,  4 );
	a1insertar_nodo_fin(lista1,  5 );
	a1mostrar_lista(lista1);
	printf("\n");
	printf("2");
    printf("\n");
    printf("Resultados del problema 2:\n");	
	promedio=calcular_promedio(lista1);
	printf("el promedio es:%d",promedio);
		return 0;
}

/*
int calcular_promedio(Listaa1 *lista){
	int num;
	int lim;
	int suma;                  //la funcon primero captura elementos de tipo int hasta recibir un -1,lugo calcula el proemdio
	int promedio;
	suma=0;
	int nodo;
	Nodoa1 *aux;
	lista=a1crear_lista();
	printf("ingresar numeros, escriba -1 para finalizar");
	scanf("%d",&num);
	while(num!=-1){
		a1insertar_nodo_ini(lista, num);
		printf("ingresar numeros, escriba -1 para finalizar");
		scanf("%d",&num); 	
	}
	lim=lista->n;
	aux = lista->heada1;
	while(aux != NULL){
		 nodo=aux->infoa1;
		 suma=nodo+suma;
		 aux = aux->siga1;	
	}
	promedio=suma/lim;
	return promedio;	
}	

*/