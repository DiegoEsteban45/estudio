
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

struct cola{
	Nodoa1 *inicio; // nodo del inicio de la cola
	Nodoa1 *final;  // nodo final de la cola
};
typedef struct cola Cola;

struct pila{
	Nodoa1 *top;
};
typedef struct pila Pila;

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
Cola *crer_cola();                             //(13)
int cola_vacia(Cola *cola);                    //(14)
void encolar(Cola *cola, int valor);           //(15)
void mostrar_cola(Cola *cola);                 //(16)
Pila *crear_pila();							   //(17)
int pila_vacia(Pila *pila);                    //(18)
void push(Pila *pila, int valor);              //(19)
void obtener_elementos(Listaa1 *l,int *A);	   //(20)	
void imprimir(int *array);                      //(21)
int* crear_array(int espacios_de_memoria);     //(22)
int binarisearchr(int num,int array[],int lim_inf,int lim_sup,int mid);  //(23)
void shellshort(int v[],int n);	                                         //(24)
Listaa1 *repetir_elementos(Listaa1 *l_1, Listaa1 *l_2);                  //(25)  

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
	if (!(a1is_lista_vacia(L1))){ // 1 lista vacia, 0 lsita no vacia, 1 falso, 0 verdadero
			new_nodo->siga1 = L1->heada1; // cuando la lista no este vacia se ejecuta el if haciendo que el nuevo nodo apunte al nodo que se encuentra en la cabeza de la lista
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
//(13)
Cola *crer_cola(){
	Cola *cola;
	cola = malloc(sizeof(Cola));
	cola->inicio=NULL;
	cola->final=NULL;
}
//(14)
int cola_vacia(Cola *cola){

	if (cola->inicio==NULL)
		return 0; //cola vacia
	else
		return 1;
}
//(15)
void encolar(Cola *cola, int valor){
	Nodoa1 *nuevo_nodo;
	nuevo_nodo = a1crear_nodo(valor);
	if(!(cola_vacia(cola))){         // 1 cola no vacia, 0 cola vacia, 1 falso, 0 verdadero
		cola->inicio=nuevo_nodo;
		cola->inicio->siga1=nuevo_nodo; // cuando la cola este vacia se ejecuta el if
		cola->final=nuevo_nodo;
	}else{
	   cola->final->siga1=nuevo_nodo;
	   cola->final=nuevo_nodo;
	}
}
//(16)
void mostrar_cola(Cola *cola){
	Nodoa1 *aux;
	if (!(!(cola_vacia(cola)))){ 
	    aux = cola->inicio;
			printf("inicio->");
	    while(aux != NULL){
		    printf(" %d", aux->infoa1);
		    aux = aux->siga1;
	    }
		printf(" <-final");
    }
}	
//(17)
Pila *crear_pila(){
	Pila *pila;
	pila=malloc(sizeof(Pila));
	pila->top=NULL;
	return pila;
}
//(18)
int pila_vacia(Pila *pila){
    if (pila->top==NULL){
		return 1;
	}else{
		return 0;
	}
}
//(19)
void push(Pila *pila, int valor){
	Nodoa1 *nuevo_nodo;
	nuevo_nodo=a1crear_nodo(valor);
	if (!pila_vacia){//si la pila no esta vacia hacer
		nuevo_nodo->siga1=pila->top;
	}
	pila->top=nuevo_nodo;
}
//(20)
void obtener_elementos(Listaa1 *l,int *A){ //crea un array simple con todos los elemntos de la lista entrelazada 
	int i;
	Nodoa1 *aux;
	i=0;
	aux= l->heada1;
	if(!(a1is_lista_vacia(l))){
		while (aux!=NULL){
			A[i]=aux->infoa1;
			i++;
			aux=aux->siga1;
		}
		A[i] = NULL;	
	}else{
		A[0] = NULL;
	}
}
//(21)
void imprimir(int *array){ // imprime el array
	int i = 0;
	printf("\narreglo -> {");
    while (*array!=NULL){
           printf(" %d",*array);
           array++;
		   i++;
        }
	printf(" } de largo %d",i);
}
//(22)
int* crear_array(int espacios_de_memoria){ //crea un un array con la cantidad de espacio requerida
	int *array;
	array=malloc(espacios_de_memoria*(sizeof(int)));
	return array;
}
//(23)
Listaa1 *repetir_elementos(Listaa1 *l_1, Listaa1 *l_2) { //repite los elemntos de la lista 1 que estan tambien en la lista 2
    int *A;
    int inicio, mitad;
    Nodoa1 *aux, *aux2;
    inicio = 0;
    A = crear_array(l_2->n);
    aux = l_1->heada1;
    obtener_elementos(l_2, A);
	shellshort(A, l_2->n);
	if(!(a1is_lista_vacia(l_1))){
		if (A[0] != NULL){
			printf("\n\n");
			printf("numeros repetidos -> [");
			while (aux != NULL){
				if (!(binarisearchr((aux->infoa1), (A), (inicio), (l_2->n), (mitad)))) {
					  aux2 = a1crear_nodo(aux->infoa1);
					  aux2->siga1 = aux->siga1;
					  aux->siga1 = aux2;
					  l_1->n = (l_1->n) + 1;
					  printf(" %d ",aux2->infoa1);
					  aux = aux2->siga1;
				}else{
					aux = aux->siga1;
				}
			}
		}else{
			return 0;
		}
	}else{
		return 0;
	}
	printf("]\n");
	return l_1;
}
//(24)
void shellshort(int v[],int n){ //ordena elementos de una array
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2)
        for(i=gap;i<n;i++)  
            for(j=i-gap;(j>=0)&&(v[j]>v[j+gap]);j=j-gap){    
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;  
            }
}
//(25)
int binarisearchr(int num,int array[],int lim_inf,int lim_sup,int mid){ //busca elemento de un array
    mid=(lim_inf+lim_sup)/2;
    if (array[mid]==num||array[mid+1]==num||array[mid-1]==num){
        return 0;
    }else if (lim_inf==mid||lim_sup==mid){
        return 1;
    }else if (num<array[mid]){
        lim_sup=(mid-1);
        return binarisearchr(num,array,lim_inf,lim_sup,mid); //POR LA IZQUIERDA 
    }else if (num>array[mid]){
        lim_inf=(mid+1);
        return binarisearchr(num,array,lim_inf,lim_sup,mid); //POR LA DERECHA
    }  
}
