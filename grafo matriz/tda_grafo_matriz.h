#include <stdio.h>
#include <stdlib.h>

struct grafo{
    int **M_A;
    int nodos;
    int aristas;
};
typedef struct grafo grafo;

grafo *crear_grafo(int nodos);
void mostrar_grafo(grafo *g);
void crear_arista_no_dirigida(grafo *g, int n_1, int n_2);
void crear_arista_dirigida(grafo *g, int n_1, int n_2);
int son_adyacentes(grafo *g,int n_1, int n_2);
int es_camino(grafo *g, int *camino, int larg);
int es_regular(grafo *g);
int grado_nodo(grafo *g, int n);

grafo *crear_grafo(int nodos){        //crea una matriz de 0
	grafo *g;
    int i,j;
    g=malloc(sizeof(grafo));
	g->M_A=malloc(sizeof(int)*nodos);
	for(i=0; i<nodos; i++){
        g->M_A[i]=malloc(sizeof(int)*nodos);
        for(j=0; j<nodos; j++){
           g->M_A[i][j]=0;
        }
    }
    g->nodos=nodos;
    g->aristas=0;
    return g; 
} 
void mostrar_grafo(grafo *g){ //muestra el grafo
    int n,i,j,a;
    n=g->nodos;
    printf("  ");
    for(a=0;a<n;a++){
        
        printf(" %d ",a);
    }
    printf("\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if (j==0) {
                printf("%d|",i);
            }
            printf(" %d ",g->M_A[i][j]);
            if (j==n-1) {
                printf("|");
            }
        }
        printf("\n");
    }    
}
void crear_arista_no_dirigida(grafo *g, int n_1, int n_2){ //int n_1 y n_2 son los dos vertices que seran conectados por una arista
	g->M_A[n_1][n_2]=1;
	g->M_A[n_2][n_1]=1;
    g->aristas++;		
}
void crear_arista_dirigida(grafo *g, int n_1, int n_2){ //arista dirigida de n_1 a n_2
    g->M_A[n_1][n_2]=1;
    g->aristas++;	
}
int son_adyacentes(grafo *g,int n_1, int n_2){ // 1 si los nodos estan conectados y 0 si no
    if ((g->M_A[n_1][n_2]==1)&&(g->M_A[n_2][n_1]==1)){
        return 1;
    }
    else{
        return 0;
    }
}
int es_camino(grafo *g, int *camino, int larg){ // retorna 1 son caminos y 0 si no
    int i;
    for(i=0;(i<larg-1);i++){
        if((g->M_A[camino[i]][camino[i+1]]!=1)&&(g->M_A[camino[i+1]][camino[i]]!=1)){
            return 0;
        }   
    }
    return 1;
}

int es_regular(grafo *g){  // retorna 1 si es regular y 0 si no
    int grado,grado_1, i,j,n;
    n=g->nodos;
    i=0;
    grado=0;
    for(j=0; j<n; j++){
        if(g->M_A[i][j]==1){
           grado++;
        }   
    }
    grado_1=grado;
    for (i = 1; i < n; i++){
        if(grado==grado_1){
            grado_1=0;
            for(j = 0; j < n; j++){
                if(g->M_A[i][j] == 1){
                grado_1++;
                }
            }         
        }else{
            return 0;
        }        
    }
    return 1;
}

int grado_nodo(grafo *g, int n){ //indica el grado del nodo
    int grado, i, j, larg;
    larg=g->nodos;
    grado=0;
    for(j=0; j<larg; j++){
        if(g->M_A[n][j]==1){
           grado++;
        }   
    }
    return grado;
}
