#include <stdio.h>
//getchar(); input introduce un caracter
//long puede almacenar numeros más grandes, 8 bytes 64 bits
//"ld" es para imprimir un long

main(){
    long numero_caracteres;
    numero_caracteres=0;
    while(getchar()!=EOF){
        numero_caracteres=numero_caracteres+1;// o ++numero_caracteres
    }   
    printf("%ld\n",numero_caracteres);
}     