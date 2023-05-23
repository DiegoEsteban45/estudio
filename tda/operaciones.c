#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tda_punto_rectangulo.h"

main(){
    float ax,ay,bx,by,cx,cy,dx,dy,area,perimetro;
    Punto *a,*b,*c,*d;
    Rectangulo *r;
    printf("punto 1:\n");
    scanf("%f",&ax);
    scanf("%f",&ay);
    printf("punto 2\n");
    scanf("%f",&bx);
    scanf("%f",&by);
    printf("punto 3\n");
    scanf("%f",&cx);
    scanf("%f",&cy);
    printf("punto 4\n");
    scanf("%f",&dx);
    scanf("%f",&dy);
    //printf("(a)%2.f-%2.f,(b)%2.f-%2.f,(c)%2.f-%2.f,(d)%2.f-%2.f",ax,ay,bx,by,cx,cy,dx,dy);
    a=crear_punto(ax,ay);
    b=crear_punto(bx,by);
    c=crear_punto(cx,cy);
    d=crear_punto(dx,dy);
    r=crear_rectangulo(a,b,c,d);
    area=area_del_rectangulo(r);
    obtener_distancia(a,b);
    perimetro=perimetro_del_rectangulo(r);
    printf("area%2.f,perimetro%2.f",area,perimetro);
}






