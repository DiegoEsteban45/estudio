#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "S10_TDAGrafoMa_A1.h"

Aristaa1 crear_arista(int v_1, int v_2, float peso){
	Aristaa1 new_arista;
	new_arista.v = v_1;
	new_arista.w = v_2;
	new_arista.peso = peso;
	return new_arista;	
}
int main(int argc,  char *argv[]) {
	//inicializacion
		Grafoa1 *grafo;
		int num_vertices;
		Aristaa1 a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17;
		num_vertices=8;

	//operaciones
		grafo=crear_grafoa1(num_vertices);
		//se crean las aristas entregadas en el archivo S10_datos_grafos_A1
		a1=crear_arista(0,1,2.5),a2=crear_arista(1,2,0.5),a3=crear_arista(2,3,4.1),a4=crear_arista(4,3,3.6);
		a5=crear_arista(3,5,1.5),a6=crear_arista(3,0,4.7),a7=crear_arista(0,5,3.2),a8=crear_arista(5,4,6.7);
		a9=crear_arista(1,4,5.8),a10=crear_arista(4,2,0.8),a11=crear_arista(5,1,4.2),a12=crear_arista(3,6,0.7);
		a13=crear_arista(4,6,2.3),a14=crear_arista(7,2,4.4),a15=crear_arista(7,0,2.3),a16=crear_arista(7,1,1.8),a17=crear_arista(4,5,1.5);
        //se agregan las aristas
		agregar_aristaa1(grafo, a1);agregar_aristaa1(grafo, a2),agregar_aristaa1(grafo, a3),agregar_aristaa1(grafo, a4),agregar_aristaa1(grafo, a5);
		agregar_aristaa1(grafo, a6),agregar_aristaa1(grafo, a7),agregar_aristaa1(grafo, a8),agregar_aristaa1(grafo, a9),agregar_aristaa1(grafo, a10);
		agregar_aristaa1(grafo, a11),agregar_aristaa1(grafo, a12),agregar_aristaa1(grafo, a13),agregar_aristaa1(grafo, a14),agregar_aristaa1(grafo, a15);
		agregar_aristaa1(grafo, a16),agregar_aristaa1(grafo, a17);
	//resultados

        printf("Resultados del problema 1:\n");
		mostrar_grafoa1(grafo);	

    	printf("\n");
    	printf("Resultados del problema 2:\n");		
    	printf("\n");

		/* PROBLEMA 3. 
		   Escriba las instrucciones necesarias para mostrar
			 el  resultado de la funci�n solicitada en el problema 3 de su actividad*/
    	printf("Resultados del problema 3:\n");		

		printf("\n\n");
		return 0;
}
