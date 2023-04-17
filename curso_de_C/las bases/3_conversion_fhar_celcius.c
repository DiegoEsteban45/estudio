//modificacion del segundo programa "2_conversion_de_...."
/*el %f es necesario para imprimir en formato flotante y al escribir %x.yf (x e y siendo un numero),
el x representa la cantidad de numero enteros a imprimir, la y representa la cantidad de numeros dcimales a imprimir 
*/

#include <stdio.h>

main(){
    float fahr,celsius;
    int lower,upper,step;            

    lower=0;    
    upper=300;                 
    step=20;  

    fahr=lower;
    printf("fahr\tcelsius\n");
    while(fahr<=upper){
         celsius=(5.0/9.0)*(fahr-32.0);
         printf("%3.0f\t%6.2f\n",fahr,celsius);
         fahr=fahr+step;
    }
}