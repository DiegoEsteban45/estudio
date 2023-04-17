/* programa de conversion de fahrenhait a celcius, la idea es crear una tabla que muestre las temperaturas en fhar a celsius
el limite de de esta conversion es llegar a los 300 fahr*/
// segunda forma de escribir un comentario
//%d imprime en formato numero y el \t imprime un espacio 




//num trans_fahr_to_celsius(argument or input)
#include <stdio.h>

main(){
    int fahr,celsius;
    int lower,upper,step;              //definicion    

    lower=0;    //inicio
    upper=300; //tope                // inicialisación
    step=20;  //incremento

    fahr=lower;
    printf("fahr\tcelsius\n");
    while(fahr<=upper){
         celsius=5*(fahr-32)/9;
         printf("%d\t%d\n",fahr,celsius);
         fahr=fahr+step;
    }
}