
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDAGrafo_LA_labS8.h"


int main(int argc,  char *argv[]) {

	Grafo *g;
    g = crear_grafo(4); //crea el grafo con 4 v?rtices
    printf("\nGrafo creado en @ = %p  con  %d vertices\n", g, g->n);
	mostrar_grafo(g);
	
	agregar_vertice(g); 	
	printf("\nGrafo creado en @ = %p  con  %d vertices\n", g, g->n);
	mostrar_grafo(g);
	printf("\n------------\n");
	
	
	
		
		
	printf("\n\n");
  return 0;
}
