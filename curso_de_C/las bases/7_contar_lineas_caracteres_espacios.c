#include <stdio.h>

main(){
    long numero_caracteres, numero_de_lineas, numero_de_espacios;
    char c;
    numero_caracteres=0;
    numero_de_lineas=0;
    numero_de_espacios=0;
    c=getchar();
    while(c!=EOF){
        if (c == '\n'){
            ++numero_de_lineas; 
        }        
        else if(c==' '){
            ++numero_de_espacios;
        }
        else{
            ++numero_caracteres;
        }
        c=getchar();
    }   
    printf("numero de carcateres %ld y numero de lineas %ld y numero de espacios %ld",numero_caracteres, numero_de_lineas, numero_de_espacios);
}      
    