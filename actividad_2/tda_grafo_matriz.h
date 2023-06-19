#include <stdio.h>

sruct GRAFO{
    int **M_A;
    int nodos;
    int aristas;
};
typedef GRAFO grafo;

grafo *crear_grafo(int nodos){        //crea una matriz de 0
	grafo g;
	g=malloc(sizeof(gafo)*nodos);
	for(i=0; i<n; i++){
        A[i]=malloc(sizeof(int)*5);
        for(j=0; j<n; j++){
            A[i][j]=0;
        }
    } 
}

void crear_arista_no_dirigida(grafo g, int n_1; int n_2){ //int v_1 y v_2 son los dos vertices que seran conectados por una arista
	g.M[n_1][n_2]=1;
	g.M[n_2][n_1]=1;
		
}


