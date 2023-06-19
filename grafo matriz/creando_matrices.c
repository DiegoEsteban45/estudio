#include <stdio.h>
#include <stdlib.h>
#include "tda_grafo_matriz.h"
int main(){
    grafo *grafo;
    int n,ad,esc,esr,grn;
    n=5;
    int A[5]={0,2,3,1,4};
    grafo=crear_grafo(n);
    crear_arista_no_dirigida(grafo,0,1);
    crear_arista_no_dirigida(grafo,0,3);
    crear_arista_no_dirigida(grafo,0,2);
    crear_arista_no_dirigida(grafo,1,3);
    crear_arista_no_dirigida(grafo,1,4);
    crear_arista_no_dirigida(grafo,2,3);
    crear_arista_no_dirigida(grafo,2,4);
    crear_arista_dirigida(grafo,4,1);
    crear_arista_dirigida(grafo,4,4);
    mostrar_grafo(grafo); 
    esc=es_camino(grafo,A,5);
    ad=son_adyacentes(grafo,0,4);
    esr=es_regular(grafo);
    grn= grado_nodo(grafo,3);

    printf("\nad%d",ad);
    printf("\nesc%d",esc);
    printf("\nesr%d",esr);
    printf("\ngrn%d",grn);


}
