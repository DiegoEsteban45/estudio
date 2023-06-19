/*Estructura de datos para grafo usando LISTA DE ADYACENCIA
 GRAFO NO PONDERADO y DIRIGIDO -- > esto se explica en c?tedra
 */ 
#include <stdbool.h>
#include <stdlib.h>
#include "S6_TDALista_A1.h"
struct grafo{
	Listaa1 **lisv; 			//Arreglo donde cada celda representa un vertice y de tipo Lista lisv es un puntero a puntero lista  lisv=&lista->lista(heada,n)
	int n; 						//n?mero de nodos del grafo
	int m; 						//numero de v?rtices del grafo
};
typedef struct grafo Grafo;

/* Tarea 1: Dibuje una representaci?n en memoria considerando 4 v?rtices 
            Identificar y comprender la operaci?n del TDA lista que debe utilizar*/
Grafo *crear_grafo(int n); //Necesito saber el n?mero de v?rtices a insertar inicialmente

/* Tarea 2: Modifique su dibujo anterior para que considere un nuevo v?rtice */
void agregar_vertice(Grafo *G); // agrega una celda (memoria) al arreglo din?mico del grafo creado

/*Tarea 3: Identificar y comprender la operaci?n del TDA lista que debe utilizar */
void mostrar_grafo(Grafo *G); 

/* Tarea 4: Implemente esta operaci?n */
void agregar_arista(Grafo *G, int v, int w); //agrega una arista (v,w) al grafo
										    // Es decir, agrega un nodo a la lista G-lisv[v]. ?Qu? m?s debe considerar?
/* PROGRAMACI?N OPERACIONES */

Grafo *crear_grafo(int n){
	Grafo *G;
	G = malloc(sizeof(Grafo));
	G->lisv = malloc(sizeof(Listaa1)*n); //se crea el grafo con la cantidad de nodos correspondiente
	for (int i=0; i<n; i++){             //se crea una lista que apunta a n listas
      G->lisv[i] = a1crear_lista(); 	
	}
	G->n = n;
	G->m = 0;
	return  G;	
}

void agregar_vertice (Grafo *G){
	G->lisv = realloc(G->lisv, sizeof(Listaa1)*(G->n + 1)); 	//realloc reasigna tama?o memoria conservando lo anterior
	G->n = G->n + 1; 
	G->lisv[G->n-1] = a1crear_lista(); 						//G->n-1 es el ultimo indice del arreglo G->lisv	
}

void mostrar_grafo(Grafo *G){ 
	printf("\n Numero de vertices:%d",G->n);
	printf("\n Numero de aristas:%d",G->m);
	for (int i=0; i<G->n; i++){
		printf("\n %d  ",i );
		mostrar_lista(G->lisv[i]);
	}
}

/* Despues de programar esta funcion usela 
   para agregar v?rtices al grafo. 
   Siga las indicaciones de su docente
   Pruebe sus resultados */
void agregar_arista(Grafo *G, int v, int w){ // v es el vertice, y w es el numero del nodo
	
	
	
	
}




/*
**LISV es un array, un puntero que apunta a un elemento de tipo lista 





*/