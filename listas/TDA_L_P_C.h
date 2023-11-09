
#include <stdio.h>
#include <stdlib.h>   
#include <stdbool.h>

/* ESTRUCTURA DE DATOS de listas simples, pilas y colas estas estructura estan creadas a partir de nodos que solo 
manejan datos de tipo int */
struct nodo{
  int info;
  struct nodo *siguiente;

};
typedef struct nodo nodo;

struct lista{
  nodo *cabeza;
  int n; //Número de nodos agregados a la lista
};
typedef struct lista lista;

struct cola{
	nodo *inicio; // nodo del inicio de la cola
	nodo *final;  // nodo final de la cola
};
typedef struct cola cola;

struct pila{
	nodo *top;
};
typedef struct pila pila;

/* Encabezados de las operaciones programadas*/

/*(1)*/	lista *crear_lista();                                   	
/*(2)*/	bool lista_vacia(lista *L1);                           	
/*(3)*/	nodo *crear_nodo(int val);                  	            
/*(4)*/	void insertar_nodo_ini(lista *L1, int val); 	             
/*(5)*/	void insertar_nodo_fin(lista *L1, int val); 				
/*(6)*/	void mostrar_lista(lista *L1);              				
/*(7)*/	int  eliminar_nodo_ini(lista *L1);          				
/*(8)*/	int  eliminar_nodo_fin(lista *L1);          				
/*(9)*/	void eliminar_nodo(lista *L1, int valE);    				
/*(10)*/nodo *buscar_Nodo(lista *L1, int val);   	   		   
/*(11)*/float calcular_promedio(lista *lista);         	   		  
/*(12)*/lista *input_list();                        	           
/*(13)*/cola *crear_cola();                          	          
/*(14)*/bool cola_vacia(cola *cola);              	             
/*(15)*/void encolar(cola *cola, int valor);           	        
/*(16)*/void mostrar_cola(cola *cola);                	          
/*(17)*/void desencolar(cola *cola);
/*(18)*/cola *input_cola();
/*(19)*/pila *crear_pila();							               
/*(20)*/bool pila_vacia(pila *pila);                               
/*(21)*/void push(pila *pila, int valor);                         
/*(22)*/void pop(pila *pila);
/*(23)*/void pop_tope(pila *pila);
/*(24)*/void vaciar_pila(pila *p);
/*(25)*/void tope(pila *pila);	
/*(26)*/pila *input_pila();
/*(27)*/void obtener_elementos(lista *l,int *A);	               	
/*(28)*/void imprimir(int *array);                               
/*(29)*/int* crear_array(int espacios_de_memoria);                 
/*(30)*/lista *repetir_elementos(lista *l_1, lista *l_2);                 
/*(31)*/void shellshort(int v[],int n);	                                          
/*(32)*/bool binarisearchr(int num,int array[],int lim_inf,int lim_sup,int mid); 
/*(33)*/void eliminar_elementos_menores(lista *l, int limite);
		nodo *nodo_final(lista *L);
		nodo *nodo_penultimo(lista *L);
		void invertir_lista(lista *L);
		lista *vaciar_lista(lista *L);
          
//(1)
lista *crear_lista(){
	lista *L1 = (lista*)malloc(sizeof(lista));  //creamos una variable l1 que de tipo lista 
  	L1->cabeza = NULL;
  	L1->n = 0;
	return L1;
}
//(2)
bool lista_vacia(lista *L1){
	if(L1->cabeza == NULL)
		return true; /*lista vacía retorna un TRUE*/
	else
		return false;
}
//(3)
nodo *crear_nodo(int val){
	nodo *new_nodo;
	new_nodo = (nodo*)malloc(sizeof(nodo));
	new_nodo->info = val;
    new_nodo->siguiente = NULL;	
  return new_nodo;
}
//(4)
void insertar_nodo_ini(lista *L1, int val){
	nodo *new_nodo;
	new_nodo = crear_nodo(val);
	if (!(lista_vacia(L1))){ 
			new_nodo->siguiente = L1->cabeza; // cuando la lista no este vacia se ejecuta el if haciendo que el nuevo nodo apunte al nodo que se encuentra en la cabeza de la lista
	}
	L1->cabeza = new_nodo;
	L1->n = L1->n + 1;  /* aumenta el número de nodos de la lista L */
}
//(5)
void insertar_nodo_fin(lista *L1, int val){
	nodo *aux, *new_nodo;
	aux = L1->cabeza;
	if(!(lista_vacia(L1))){
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		new_nodo = crear_nodo(val);
		aux->siguiente = new_nodo;
		L1->n++; /* aumenta el número de nodos de la lista L */
	}else{
		printf("lista vacia");
	}	
}
//(6)
void mostrar_lista(lista *L1){
	nodo *aux;
	if (!(lista_vacia(L1))){ 
		printf("\n\nCantidad de elementos %d\n",L1->n);
	    aux = L1->cabeza;
			printf("\nL->");
	    while(aux != NULL){
		    printf(" %d", aux->info);
		    aux = aux->siguiente;
	    }
    }else{
		printf("\nlista vacia\n");
	}
}
//(7)
int eliminar_nodo_ini(lista *L1){
	nodo *aux;
	int e=0;
	if (!lista_vacia(L1)) {
		aux =  L1->cabeza; 
		L1->cabeza = L1->cabeza->siguiente; 
		e = aux->info;
		L1->n = L1->n  - 1; /* descuenta el número de nodos de la lista */
		aux->siguiente = NULL;
		free (aux) ; 
	}
	return e;
}
void eliminar_nodo_inicio(lista *L){
	nodo *aux;
	if (!lista_vacia(L)) {
		aux =  L->cabeza; 
		L->cabeza = L->cabeza->siguiente; 
		L->n = L->n - 1;
		aux->siguiente = NULL;
		free (aux) ; 
	}
}
//(8)
int  eliminar_nodo_fin(lista *L1){
	nodo *aux, *auxE;
	int e=0;
	if (!lista_vacia(L1)){
		/* mover el aux al penúltimo nodo */
		aux = L1->cabeza;
		while(aux->siguiente->siguiente !=NULL){
				aux = aux->siguiente;
		}		
		e = aux->siguiente->info;
		L1->n = L1->n - 1;
		auxE = aux->siguiente;
		aux->siguiente = NULL;
		free (auxE) ; 
	}
	return e;	
}
//(9)
nodo *buscar_nodo(lista *L1, int val){
	nodo *aux;
	aux = L1->cabeza;
	while(aux != NULL){
		if(aux->info != val)
				aux = aux->siguiente;
		else
				return aux;
	}
   return aux;
}
//(10)
void eliminar_nodo(lista *L1, int val){
	nodo *auxE, *aux; 
	int e;
	if  (!lista_vacia(L1)) {
		auxE = buscar_nodo(L1,val);
		if (auxE != NULL){
			if (auxE == L1->cabeza){  
			   e = eliminar_nodo_ini(L1);
			}else {
			   if (auxE->siguiente == NULL){ 
						e = eliminar_nodo_fin(L1);
			   }else {
						/* Si el nodo a eliminar no está en el inicio ni en el fin 
						   mueve el aux al nodo anterior al que se elimina */
						aux = L1->cabeza;
						while(aux->siguiente != auxE){
								aux = aux -> siguiente;
						}
						auxE = aux->siguiente;
						aux->siguiente = auxE->siguiente;
						L1->n = L1->n - 1;
						auxE->siguiente = NULL;
						free (auxE) ; 
				} 
			}
		}
	}	
} 
//(11)
float calcular_promedio(lista *lista){ /*calcula el promedio de elementos de una lista*/
	int suma;
	float promedio;
	int nodo_info;
	nodo *aux;
	suma = 0;
	aux = lista->cabeza;
	while(aux != NULL){
		 nodo_info=aux->info;
		 suma=nodo_info+suma;
		 aux = aux->siguiente;	
	}
	promedio=suma/(lista->n);
	return promedio;	
}
//(12)
lista *input_list(){ /* crea una lista por entrada*/
	int num;
	int num_2;
	lista *lista;
	lista = crear_lista();
	num = 0;
	printf("ingresar numeros, escriba -1 para finalizar\n");
	scanf("%d", &num_2);
	if(num_2 != -1){
		insertar_nodo_ini(lista, num_2);
		while(num != -1){
			printf("ingresar numeros, escriba -1 para finalizar\n");
			scanf("%d",&num);
			if (num != -1){
				insertar_nodo_fin(lista, num);
			}
		}				
	}
	return lista; 
}
//(13) OPERACIONES DE COLA
cola *crear_cola(){
	cola *cola;
	cola = malloc(sizeof(cola));
	cola->inicio=NULL;
	cola->final=NULL;
}
//(14) 
bool cola_vacia(cola *cola){

	if (cola->inicio==NULL)
		return true; //cola vacia
	else
		return false;
}
//(15)
void encolar(cola *cola, int valor){
	nodo *nuevo_nodo;
	nuevo_nodo = crear_nodo(valor);
	if(cola_vacia(cola)){         // cuando la cola este vacia se ejecuta el if
		cola->inicio=nuevo_nodo;	
		cola->final=nuevo_nodo;
	}else{
	   cola->final->siguiente=nuevo_nodo;
	   cola->final=nuevo_nodo;
	}
}
//(16)
void mostrar_cola(cola *cola){
	nodo *aux;
	if (cola_vacia(cola)){ 
		printf("cola vacia");	
	}else{
		aux = cola->inicio;
		printf("inicio->");
	    while(aux != NULL){
		    printf(" %d", aux->info);
		    aux = aux->siguiente;
	    }
		printf(" <-final");
	}

}
//(17)
void desencolar(cola *cola){
	nodo *aux;
	if(cola_vacia(cola)){
		 printf("\ncola vacia\n");	
	}else{
		aux=cola->inicio;
		cola->inicio=cola->inicio->siguiente;
		free(aux); 
	}
}
//(18)
cola *input_cola(){
	cola *new_cola;
	int num;
	new_cola=crear_cola();
	printf("escriba un numero, escriba -1 para finalizar\n");
	scanf("%d",&num);
	if(num!=-1){
		encolar(new_cola, num);
		printf("escriba un numero, escriba -1 para finalizar\n");
		scanf("%d",&num);
		while (num!=-1){
			encolar(new_cola, num);
			printf("escriba un numero, escriba -1 para finalizar\n");
			scanf("%d",&num);		
		}	
	}
	return new_cola;
}
//(19) OPERACIONES DE PILA
pila *crear_pila(){
	pila *pila;
	pila=malloc(sizeof(pila));
	pila->top=NULL;
	return pila;
}
//(20)
bool pila_vacia(pila *pila){
    if (pila->top==NULL){
		return true;
	}else{
		return false;
	}
}
//(21)
void push(pila *pila, int valor){
	nodo *nuevo_nodo;
	nuevo_nodo=crear_nodo(valor);
	if (!pila_vacia(pila)){//si la pila no esta vacia hacer
		nuevo_nodo->siguiente=pila->top;
	}
	pila->top=nuevo_nodo;
}
//(22)
void pop(pila *pila){
	nodo *aux;
	if(!pila_vacia(pila)){
		aux = pila->top;
		pila->top=pila->top->siguiente;
		free(aux);
	}else{
		printf("pila vacia");
	}
}
//(23)
void pop_tope(pila *pila){// muetra lo que elimina
	nodo *aux;
	if(!pila_vacia(pila)){
		aux = pila->top;
		printf("\ntope=%d\n",aux->info);
		pila->top=pila->top->siguiente;
		free(aux);
	}else{
		printf("pila vacia");
	}
}
//(24)
void vaciar_pila(pila *p){
	if(pila_vacia(p)){
		printf("pila ya vacia");
	}else{
		while(!pila_vacia(p)){//mientra la pila sea distinto de vacio hacer
		      pop_tope(p);
		}
		printf("\npila vaciada\n");
	}
}
//(25)
void tope(pila *pila){
	if(!pila_vacia(pila)){
		printf("tope:%d",pila->top->info);
	}
	else{
		printf("pila vacia");
	}
}
//(26)
pila *input_pila(){
	pila *new_pila;
	int num;
	new_pila=crear_pila();
	printf("escriba un numero, escriba -1 para finalizar\n");
	scanf("%d",&num);
	if(num!=-1){
		push(new_pila,num);
		printf("escriba un numero, escriba -1 para finalizar\n");
		scanf("%d",&num);
		while (num!=-1){
			push(new_pila, num);
			printf("escriba un numero, escriba -1 para finalizar\n");
			scanf("%d",&num);		
		}	
	}
	return new_pila;	
}
//(27)
void obtener_elementos(lista *l,int *A){ //crea un array simple con todos los elemntos de la lista entrelazada 
	int i;
	nodo *aux;
	i=0;
	aux= l->cabeza;
	if(!(lista_vacia(l))){
		while (aux!=NULL){
			A[i]=aux->info; // 0 1 2 3 4        5
			i++;              // 1 2 3 4 5->null -1
			aux=aux->siguiente;
		}
		A[i] = -1;	
	}else{
		A[0] = -1;
	}
}
//(28)
void imprimir(int *array){ // imprime el array
	int i = 0;
	printf("\narreglo -> {");
    while (*array!=-1){
           printf(" %d",*array);
           array++;
		   i++;
        }
	printf(" } de largo %d",i);
}
//(29)
int* crear_array(int espacios_de_memoria){ //crea un un array con la cantidad de espacio requerida
	int *array;
	array=malloc(espacios_de_memoria*(sizeof(int)));
	return array;
}
//(30)
lista *repetir_elementos(lista *l_1, lista *l_2) { //repite los elementos de la lista 1 que estan tambien en la lista 2
    int *A;  //variabe de tipo puntero a entero 
    int inicio, mitad;
    nodo *aux, *aux2;
    inicio = 0;
    A = crear_array(l_2->n+1);  // A ahora alamacena n cantiadad de enteros
    aux = l_1->cabeza;
    obtener_elementos(l_2, A);
	shellshort(A, l_2->n);
	if(!(lista_vacia(l_1))){
		if (A[0] != -1){
			printf("\n\n");
			printf("numeros repetidos -> [");
			while (aux != NULL){
				if ((binarisearchr((aux->info), (A), (inicio), (l_2->n), (mitad)))) {
					  aux2 = crear_nodo(aux->info);
					  aux2->siguiente = aux->siguiente;
					  aux->siguiente = aux2;
					  l_1->n = (l_1->n) + 1;
					  printf(" %d ",aux2->info);
					  aux = aux2->siguiente;
				}else{
					aux = aux->siguiente;
				}
			}
		}else{
			free(A);
			return 0;
		}
	}else{
		free(A);
		return 0;
	}
	free(A);
	printf("]\n");
	return l_1;
}
//(31)
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
//(32)
bool binarisearchr(int num,int array[],int lim_inf,int lim_sup,int mid){ //busca elemento de un array
    mid=(lim_inf+lim_sup)/2;
    if (array[mid]==num||array[mid+1]==num||array[mid-1]==num){
        return true;
    }else if (lim_inf==mid||lim_sup==mid){
        return false;
    }else if (num<array[mid]){
        lim_sup=(mid-1);
        return binarisearchr(num,array,lim_inf,lim_sup,mid); //POR LA IZQUIERDA 
    }else if (num>array[mid]){
        lim_inf=(mid+1);
        return binarisearchr(num,array,lim_inf,lim_sup,mid); //POR LA DERECHA
    }  
}
//(33)
void eliminar_elementos_menores(lista *l, int limite){//elimina los elementores a un numero dado 
    if (!lista_vacia(l)&&(l->n>1)){
        nodo *anterior =l->cabeza;
        while((l->cabeza->info < limite)&&(!lista_vacia(l))){
            anterior=l->cabeza;
            l->cabeza=l->cabeza->siguiente;
            free(anterior);
            l->n--;
        } 
        anterior=l->cabeza;
		nodo *actual=anterior->siguiente;
        nodo *sucesor=actual->siguiente;
        nodo *ante_penultimo=anterior;
        while ((sucesor!=NULL)){
            if (actual->info<limite){   
                free(anterior->siguiente);
                anterior->siguiente=sucesor;
                l->n--;
                ante_penultimo=anterior;
                actual=sucesor;
                sucesor=actual->siguiente;
            }else{
                anterior=anterior->siguiente;
                ante_penultimo=anterior;
                actual=anterior->siguiente;
                sucesor=actual->siguiente;    
            }  
        }
        if (actual->info<limite){
            free(ante_penultimo->siguiente);
            ante_penultimo->siguiente=NULL;
			l->n--;
        }
    }else if(l->cabeza->info<limite){
            eliminar_nodo_ini(l);
    }
}
//(34)
nodo *nodo_final(lista *L){
	nodo *aux;
	aux=L->cabeza;
	while(aux->siguiente!=NULL){
		aux=aux->siguiente;
	}
	return aux;
}
//(35)
nodo *nodo_penultimo(lista *L){
	nodo *aux;
	aux=L->cabeza;
	while(aux->siguiente->siguiente!=NULL){
		aux=aux->siguiente;
	}
	return aux;
}
//(36)
void invertir_lista(lista *L){
	nodo *penultimo,*final,*anterior;
	nodo *aux=L->cabeza;
	int repeticiones = L->n;
	int i;
	for (i=0;i<(repeticiones-1);i++){
		penultimo=nodo_penultimo(L);
		final=penultimo->siguiente;
		final->siguiente=aux;
		penultimo->siguiente=NULL;
		if (i==0){
			L->cabeza=final;
			anterior=final;	
		}else{
			anterior->siguiente=final;
			anterior=final;
		}
	}
}
//(37)
lista *vaciar_lista(lista *L){
	while(!lista_vacia(L)){
		eliminar_nodo_inicio(L);
	}
	return(L);
}
//(38)
void ordenar_lista(lista *L,int orden){
	if(orden==1||orden==2){
		nodo *aux,*posicion,*nod_menor,*anterior,*posterior,*aux1;
		if (orden==1){
			int menor;
			aux=L->cabeza;
			while(aux!=NULL){
				menor=aux->info;
				aux1=aux->siguiente;
				anterior=aux;
				posterior=aux1->siguiente;
				while(aux1!=NULL){
					if (menor>(aux1->info)){
						menor=aux1->info;
						aux1->siguiente=aux->siguiente;
						anterior->siguiente=aux;
						aux->siguiente=posterior;
						anterior=aux1;
						aux1=aux1->siguiente;
						posterior=aux1->siguiente;
					}else{
						anterior=aux1;
						aux1=aux1->siguiente;
						posterior=aux1->siguiente;
				
					}	
				}
			}			
		}
	}
}

