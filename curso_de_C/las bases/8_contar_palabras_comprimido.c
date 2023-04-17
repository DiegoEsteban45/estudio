#include <stdio.h>
#define IN 1 //estamos definiendo constantes que no van a varias su contenido
#define OUT 0 

main(){
    int numero_de_palabras,c,state;
    state=OUT;
    numero_de_palabras=0;
    while((c=getchar())!=EOF){
        if (c=='\n'||c==' '||c=='\t')
            state=OUT;
               
        else if(state==OUT){
            ++numero_de_palabras;
            state=IN;
        }    
    }     
    printf("numero de palabras %d", numero_de_palabras);
} 
