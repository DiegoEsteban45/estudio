
#include <stdio.h>

int main(){
    int *p;  // puntero a entero
    int x = 450;
    p = &x;	//se dice que “p apunta a x” es decir p ya almacena la direccion de x, ya para acceder al contenido de x se usa *p
    printf("%p\n",  p);
    printf("%d\n", *p);//*p muestra el contenido de x
    *p = 300; //con *p accedo al contenido que almacena la variable x por lo tanto ahora x es 300
    printf("%d\n", x);


    x = 10;
    int *puntero = &x;  // Obteniendo la dirección de memoria de 'x'

    printf("Valor de x: %d\n", x);
    printf("Direccion de memoria de x: %p\n", &x);
    printf("Valor almacenado en el puntero: %p\n", puntero);
    printf("Valor almacenado en el *puntero: %d\n", *puntero);

    //un dato de tipo puntero debe recibir si o si direcciones de memoria 

}
