
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

Listaa1 *a1crear_lista();
int a1is_lista_vacia(Listaa1 *L1);
Nodoa1 *a1crear_nodo(int val);
void a1insertar_nodo_ini(Listaa1 *L1, int val); 
void a1insertar_nodo_fin(Listaa1 *L1, int val);
void a1mostrar_lista(Listaa1 *L1);
int  a1eliminar_nodo_ini(Listaa1 *L1);
int  a1eliminar_nodo_fin(Listaa1 *L1);
void a1eliminar_nodo(Listaa1 *L1, int valE); /* eliminar para valor dado*/
Nodoa1 *a1buscar_Nodo(Listaa1 *L1, int val); /* retorna la dirección del nodo */
int calcular_promedio(Listaa1 *lista);


/* Programación de las Operaciones ELEMENTALES
  IMPORTANTE: No modifique estas operaciones ni agregue nuevas*/

Listaa1 *a1crear_lista(){
	Listaa1 *L1 = (Listaa1*)malloc(sizeof(Listaa1));
  L1->heada1 = NULL;
  L1->n = 0;
	return L1;
}

int a1is_lista_vacia(Listaa1 *L1){
	if(L1->heada1 == NULL)
		return 1; /*lista vacía retorna un 1*/
	else
		return 0;
}

Nodoa1 *a1crear_nodo(int val){
	Nodoa1 *new_nodo;
	new_nodo = (Nodoa1*)malloc(sizeof(Nodoa1));
	new_nodo->infoa1 = val;
  new_nodo->siga1 = NULL;	
  return new_nodo;
}


void a1insertar_nodo_ini(Listaa1 *L1, int val){
	Nodoa1 *new_nodo;
	new_nodo = a1crear_nodo(val);
	if (!(a1is_lista_vacia(L1))){ 
			new_nodo->siga1 = L1->heada1;
	}
	L1->heada1 = new_nodo;
	L1->n = L1->n + 1;  /* aumenta el número de nodos de la lista L */
}

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

int calcular_promedio(Listaa1 *lista){
	int num;
	int lim;
	int suma;                    //la funcon primero captura elementos de tipo int hasta recibir un -1,lugo calcula el promedio de los elemntos
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
