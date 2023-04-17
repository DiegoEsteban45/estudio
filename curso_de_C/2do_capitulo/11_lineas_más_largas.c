/*
    CURSO C LIBRO KERNIGHAN & RITCHIE
    linea más larga
    capitulo2, arreglos, funciones
    herramientas: arrays de caracteres
*/


/* resumen: la funcion getline recibe una cadena de caracteres y entrega su largo, la funcion copy sirve para almacenar 
la cadena de caracteres más larga*/
#include <stdio.h>
#define MAXLINE 1000 /*tamaño máximo de la línea de entrada*/

int getline2(char line[],int maxline);
void copy(char to[],char from[]);

/*Imprime la linea de entrada más larga*/
main(){
    int len;  /*longitud de linea actual*/
    int max; /*maxima longitud vista hasta la frcha*/
    char line[MAXLINE]; /*linea actual*/
    char longest[MAXLINE]; /*linea más larga*/
    max=0;
    while((len=getline2(line,MAXLINE))>0)
        if(len>max){
            max=len;
            copy(longest,line);
        }
    if(max>0)
        printf("linea mas larga <%s> de largo %d ",longest,max);

    return 0;
}
/*getline: lee una linea en s, regresa su longitud*/
int getline2(char s[],int lim){
    int c,i;
    for(i=0;(i<lim-1)&&((c=getchar())!=EOF)&&(c!='\n');++i)
        s[i]=c;
    if(c=='\n'){
        s[i]=c;
        ++i;
    }
    s[i]='\0';/* el "\0" significa caracter nulo y debe ser incluido al final de una cadena de caracteres*/
    return i;
}

/*copy: copia from hacia to*/
void copy(char linea_mas_larga[],char linea_actual[]){
    int i;
    i=0;
    while((linea_mas_larga[i]=linea_actual[i])!='\0')           
            ++i;
}


/*   
HOLA    HOLA MUNDO
0123    0123456789     */