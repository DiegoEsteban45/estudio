#include <stdio.h>
//getchar(); input introduce un caracter
//putchar(caracter); output del caracter(solo imprime un caracter a la vez)
main(){
    int caracter;
    printf("presiona lo que sea\n");
    caracter=getchar(); 
    while(caracter!=EOF ){
         putchar(caracter);
         printf("\n");
         caracter=getchar(); 
         

    }   

}     