#include <stdio.h>
#define IN 1 //estamos definiendo constantes que no van a varias su contenido
#define OUT 0 

main(){
    long numero_caracteres, numero_de_lineas, numero_de_espacios, numero_de_palabras, numero_de_numeros;
    int c, state;
    state=OUT;
    numero_caracteres=numero_de_lineas=numero_de_espacios=numero_de_palabras=0;
    while((c=getchar())!=EOF){
        if (c =='\n'){
            ++numero_de_lineas;
            if (state==IN){
                ++numero_de_palabras;
                state=OUT;
            }          
        }        
        else if(c==' '){
            ++numero_de_espacios;
            if (state==IN){
                ++numero_de_palabras;
                state=OUT;
            }
        }
        else if (c=="\t"){
             if (state==IN){
                ++numero_de_palabras;
                state=OUT;
            }
        }
        else{
            ++numero_caracteres;
            state=IN;
        }
    }
       
    printf("numero de carcateres %ld y numero de lineas %ld y numero de espacios %ld y numero de palabras %ld",numero_caracteres, numero_de_lineas, numero_de_espacios,numero_de_palabras);
} 


