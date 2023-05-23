#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*estructura de datos del TDA punto */
struct punto{
	float x;
	float y;
};
typedef struct punto Punto;
struct rectangulo{
	Punto *pt1;
	Punto *pt2;
	Punto *pt3;
	Punto *pt4;
};
typedef struct rectangulo Rectangulo;

/* Encabezados de las funciones (operaciones del TDA Punto) */
Punto *crear_punto(float n1, float n2);
Rectangulo *crear_rectangulo(Punto *a, Punto *b, Punto *c, Punto *d);
float area_del_rectangulo(Rectangulo *r);
int obtener_cuadrante(Punto *P);
void mostrar_punto(Punto *A);
void deplazar_punto(float dx, float dy, Punto *A);
float obtener_distancia_desde_origen(Punto *A);
float obtener_distancia(Punto *A, Punto *B);
//Punto *punto_medio(Punto *A, Punto *B);


/* Programación de las operaciones implementadas */
Punto *crear_punto(float n1, float n2){
	Punto *p;
	p = (Punto*)malloc(sizeof(Punto)); //malloc devuelve la direccion del bloque que reservo.
	p->x = n1;
	p->y = n2;
	return p;
}
Rectangulo *crear_rectangulo(Punto *a, Punto *b, Punto *c, Punto *d){
	Rectangulo *r;
	float lado1,lado2,lado3,lado4;                     
	r =(Rectangulo*)malloc(sizeof(Rectangulo));            
	r->pt1=a;
	r->pt2=b;
	r->pt3=c;
	r->pt4=d;
	if ((obtener_distancia(a,b)==obtener_distancia(c,d))&&(obtener_distancia(b,d)==obtener_distancia(a,c))&&(obtener_distancia(a,b)!=obtener_distancia(a,c))){
		return r;
	}else{
		return NULL;	
	}
}
//proponga una alternativa de función
int obtener_cuadrante(Punto *P){
	if (P->x >= 0 && P->y>=0) return 1;
	if (P->x <  0 && P->y>=0) return 2;
	if (P->x <  0 && P->y<0) return 3;
	if (P->x >= 0 && P->y<0) return 4;
}

void mostrar_punto(Punto *A){
	printf("\n (%f,%f)", A->x, A->y);
}

//proponga el desplazamiento en dirección y magnitud
void deplazar_punto(float dx, float dy, Punto *A){
	A->x = A->x + dx; 
	A->y = A->y + dy; 
}

float obtener_distancia_desde_origen(Punto *A){
	  float d;
	  d = pow((A->y*A->y + A->x * A->x ) , 0.5 );
	  return d;  
}

float obtener_distancia(Punto *A, Punto *B){
	//d = ( (yb-ya)^2 + (xb – xa)^2 )^(1/2)
	float d=0;
	d = sqrt( pow((B->y - A->y),2) + pow((B->x - A->x),2) );
	return d;
}
float area_del_rectangulo(Rectangulo *r){
	float lado1,lado2,area;
	lado1=obtener_distancia(r->pt1,r->pt2);
	lado2=obtener_distancia(r->pt2,r->pt4);
	area=lado1*lado2;
	return area;
}

float perimetro_del_rectangulo(Rectangulo *r){
	float perimetro;
	perimetro=((obtener_distancia(r->pt1,r->pt2))*2)+((obtener_distancia(r->pt1,r->pt3))*2);
	return perimetro;
}

/* En el código proporcionado, p es un puntero de tipo Punto que apunta a un objeto de tipo Punto.

Después de asignar memoria dinámicamente para el objeto Punto utilizando malloc, p apunta a esa ubicación de memoria asignada. Los miembros x e y del objeto Punto se pueden acceder a través de p utilizando el operador de flecha (->).

En resumen, p es un puntero que apunta a un objeto Punto, y se puede acceder a los miembros x e y del objeto utilizando p->x y p->y, respectivamente.*/
