
#include <stdio.h>
#include <stdlib.h>

/* ESTRUCTURA DE DATOS  del TDA lista  */
struct nodoa1{
  int infoa1;
  struct nodoa1 *siga1;
};
typedef struct nodoa1 Nodoa1;

struct listaa1{
  Nodoa1 *heada1;
  int n; //Número de nodos agregados a la lista
};
typedef struct listaa1 Listaa1;


/* Encabezados de las operaciones programadas*/

Listaa1 *a1crear_lista();                       //(1)
int a1is_lista_vacia(Listaa1 *L1);              //(2)
Nodoa1 *a1crear_nodo(int val);                  //(3)
void a1insertar_nodo_ini(Listaa1 *L1, int val); //(4) 
void a1insertar_nodo_fin(Listaa1 *L1, int val); //(5)
void a1mostrar_lista(Listaa1 *L1);              //(6)
int  a1eliminar_nodo_ini(Listaa1 *L1);          //(7)
int  a1eliminar_nodo_fin(Listaa1 *L1);          //(8)
void a1eliminar_nodo(Listaa1 *L1, int valE);    //(9) /*eliminar para valor dado*/
Nodoa1 *a1buscar_Nodo(Listaa1 *L1, int val);   //(10) /*retorna la dirección del nodo*/
int calcular_promedio(Listaa1 *lista);         //(11)
Listaa1 *input_list();                         //(12)
//(1)
Listaa1 *a1crear_lista(){
	Listaa1 *L1 = (Listaa1*)malloc(sizeof(Listaa1));
  L1->heada1 = NULL;
  L1->n = 0;
	return L1;
}
//(2)
int a1is_lista_vacia(Listaa1 *L1){
	if(L1->heada1 == NULL)
		return 1; /*lista vacía retorna un 1*/
	else
		return 0;
}
//(3)
Nodoa1 *a1crear_nodo(int val){
	Nodoa1 *new_nodo;
	new_nodo = (Nodoa1*)malloc(sizeof(Nodoa1));
	new_nodo->infoa1 = val;
    new_nodo->siga1 = NULL;	
  return new_nodo;
}
//(4)
void a1insertar_nodo_ini(Listaa1 *L1, int val){
	Nodoa1 *new_nodo;
	new_nodo = a1crear_nodo(val);
	if (!(a1is_lista_vacia(L1))){ // el if se ejecuta cuando la lista no esta vacia es decir la funcion alis retorna 0 y el ! lo tomma como verdadero 
			new_nodo->siga1 = L1->heada1;
	}
	L1->heada1 = new_nodo;
	L1->n = L1->n + 1;  /* aumenta el número de nodos de la lista L */
}
//(5)
void a1insertar_nodo_fin(Listaa1 *L1, int val){
	Nodoa1 *aux, *new_nodo;
	aux = L1->heada1;
	while(aux->siga1 !=NULL){
		aux = aux->siga1;
	}
	new_nodo = a1crear_nodo(val);
	aux->siga1 = new_nodo;
	L1->n++; /* aumenta el número de nodos de la lista L */
}
//(6)
void a1mostrar_lista(Listaa1 *L1){
	Nodoa1 *aux;
	if (!(a1is_lista_vacia(L1))){ 
		printf("\n\nCantidad de elementos %d\n",L1->n);
	    aux = L1->heada1;
			printf("\nL->");
	    while(aux != NULL){
		    printf(" %d", aux->infoa1);
		    aux = aux->siga1;
	    }
    }
}
//(7)
int a1eliminar_nodo_ini(Listaa1 *L1){
	Nodoa1 *aux;
	int e=0;
	if (!a1is_lista_vacia(L1)) {
		aux =  L1->heada1; 
		L1->heada1 = L1->heada1->siga1; 
		e = aux->infoa1;
		L1->n = L1->n  - 1; /* descuenta el número de nodos de la lista */
		aux->siga1 = NULL;
		free (aux) ; 
	}
	return e;
}
//(8)
int  a1eliminar_nodo_fin(Listaa1 *L1){
	Nodoa1 *aux, *auxE;
	int e=0;
	if (!a1is_lista_vacia(L1)){
		/* mover el aux al penúltimo nodo */
		aux = L1->heada1;
		while(aux->siga1->siga1 !=NULL){
				aux = aux->siga1;
		}		
		e = aux->siga1->infoa1;
		L1->n = L1->n - 1;
		auxE = aux->siga1;
		aux->siga1 = NULL;
		free (auxE) ; 
	}
	return e;	
}
//(9)
Nodoa1 *a1buscar_nodo(Listaa1 *L1, int val){
	Nodoa1 *aux;
	aux = L1->heada1;
	while(aux != NULL){
		if(aux->infoa1 != val)
				aux = aux->siga1;
		else
				return aux;
	}
   return aux;
}
//(10)
void a1eliminar_nodo(Listaa1 *L1, int val){
	Nodoa1 *auxE, *aux; 
	int e;
	if  (!a1is_lista_vacia(L1)) {
		auxE = a1buscar_nodo(L1,val);
		if (auxE != NULL){
			if (auxE == L1->heada1){  
			   e = a1eliminar_nodo_ini(L1);
			}else {
			   if (auxE->siga1 == NULL){ 
						e = a1eliminar_nodo_fin(L1);
			   }else {
						/* Si el nodo a eliminar no está en el inicio ni en el fin 
						   mueve el aux al nodo anterior al que se elimina */
						aux = L1->heada1;
						while(aux->siga1 != auxE){
								aux = aux -> siga1;
						}
						auxE = aux->siga1;
						aux->siga1 = auxE->siga1;
						L1->n = L1->n - 1;
						auxE->siga1 = NULL;
						free (auxE) ; 
				} 
			}
		}
	}	
} 
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
	num=0;
	printf("ingresar numeros, escriba -1 para finalizar\n");
	scanf("%d", &num_2);
	a1insertar_nodo_ini(lista, num_2);
	while(num!=-1){
		printf("ingresar numeros, escriba -1 para finalizar\n");
		scanf("%d",&num);
		if (num!=-1){
			a1insertar_nodo_fin(lista, num);
		}		
	}
	return lista; 
}

