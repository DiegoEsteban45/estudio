//modificacion del tercer programa "3_conversion_de_...."
/*el %f es necesario para imprimir en formato flotante y al escribir %x.yf (x e y siendo un numero),
el x representa la cantidad de numero enteros a imprimir, la y representa la cantidad de numeros dcimales a imprimir 
ahora trabajaremos con ciclo for*/

#include <stdio.h>

main(){
    int fahr,upper;
    float celsius;             
    upper=300;                
    printf("fahr\tcelsius\n");
    for(fahr=0;fahr<=upper;fahr=fahr+20){      // for(inicialización;condicion;actualizacion)
        celsius=(5.0/9.0)*(fahr-32.0);
        printf("%3d\t%6.1f\n",fahr,celsius);
    }    
}