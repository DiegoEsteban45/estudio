//Estructura de datos para grafo con MATRIZ DE ADYACENCIA
// Grafo PONDERADO.
#include <stdbool.h>
struct a1grafo{
	float **Mad;
	int n;
	int m;
};
typedef struct a1grafo Grafoa1;
struct a1arista{
	int v,w;
	float peso;
};
typedef struct a1arista Aristaa1;

//Encabezado Operaciones
Grafoa1 *crear_grafoa1(int n);
bool agregar_aristaa1(Grafoa1 *g, Aristaa1 a);
void mostrar_grafoa1(Grafoa1 *g);
bool eliminar_aristaa1(Grafoa1 *g, Aristaa1 a);
bool existe_aristaa1(Grafoa1 *g, Aristaa1 a);
bool existe_verticea1(Grafoa1 *g, int v);
int grado_verticea1(Grafoa1 *g, int v);
int *adyacentes_verticea1(Grafoa1 *g, int v);
void mostrar_adyacentesa1(Grafoa1 *g, int v);


// Programaci�n Operaciones

int grado_verticea1(Grafoa1 *g, int v){
	int cuenta=0;
	if (existe_verticea1(g,v)){ // existe v�rtice v?
		for (int j=0; j<g->n; j++) {
			if (g->Mad[v][j] != 0.0)
				cuenta = cuenta + 1;
		}
	}
	return cuenta;
}

int *adyacentes_verticea1(Grafoa1 *g, int v){
	int *adyacentes = NULL, k=0;
	if (grado_verticea1(g,v)){ // existe v�rtice v?
		adyacentes = (int*)malloc(sizeof(int) * grado_verticea1(g,v));
		for (int j=0; j<g->n; j++) {
			if (g->Mad[v][j] != 0.0){
					adyacentes[k] = j;
					k = k + 1;
			}
		}
	} //else printf("\n  adyacentes es NULL");
	return adyacentes;
}

Grafoa1 *crear_grafoa1(int n){
	Grafoa1 *g;
	g = (Grafoa1 *)malloc(sizeof(Grafoa1));
	g->Mad = (float **)malloc(sizeof(float *)*n);
	for (int i=0; i<n; i++){
      g->Mad[i] = (float *)malloc(sizeof(float)*n);
	}
	//Todas las aristas M[i][j] de la matriz quedan inactivas (sin conexi�n)
	for (int i=0; i<n;i++) {
		for (int j=0; j<n;j++) 
				g->Mad[i][j] = 0.0;
	}
  g->n = n;
  g->m = 0;
	return  g;	
}

void mostrar_grafoa1(Grafoa1 *g){ 
	printf("\n Numero de vertices:%d",g->n);
	printf("\n Numero de aristas:%d",g->m);
	printf("\n");
	for (int i=0; i < g->n; i++){ 
		for (int j=0; j < g->n; j++){
			printf("%.2f ", g->Mad[i][j]);
		}
		printf("\n");
	}
}

bool agregar_aristaa1(Grafoa1 *g, Aristaa1 a){
	if (existe_verticea1(g,a.v)){ // existe vertice v?
		if (existe_verticea1(g,a.w)){ // existe vertice w?
				g->Mad[a.v][a.w] = a.peso;
				g->m = g->m + 1;
				return true;
		}
	}
	return false;
}

bool eliminar_aristaa1(Grafoa1 *g, Aristaa1 a){
	if (existe_verticea1(g,a.v)){ // existe v�rtice v?
		if (existe_verticea1(g,a.w)){ // existe v�rtice w?
				g->Mad[a.v][a.w] = 0.0;
				g->m = g->m - 1;
				return true;
		}
	}
	return false;
}

bool existe_verticea1(Grafoa1 *g, int v){
	if (v < g->n)
		return true;
	else
		return false;
}

bool existe_aristaa1(Grafoa1 *g, Aristaa1 a){
	if (existe_verticea1(g,a.v)){ // existe v�rtice v?
		if (existe_verticea1(g,a.w)){ // existe v�rtice w?
			if (g->Mad[a.v][a.w] != 0.0)
				return true;
		}
	}
	return false;
}

void mostrar_adyacentesa1(Grafoa1 *g, int v){
			//Se asume que antes de llamar a esta operaci�n ha validado que adyacentes existe
			for (int j=0; j<g->n; j++) {
				if (g->Mad[v][j] != 0.0){
						printf("\n  %d", j);
			  }
		  }
}









