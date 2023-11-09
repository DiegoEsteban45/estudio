#include <stdio.h>		//Biblioteca de funciónes básicas de C.
#include <stdlib.h>	

typedef struct persona
{
    char* nombre;
    int edad;
    int ciudades;
}persona;

typedef struct Lista
{
	persona *persona; ;	
	int tam;		
}Lista;


int main(int argc, char const *argv[])
{
    FILE* entrada;
    FILE* salida;
    char* entrada_name;
    char* salida_mame;
    char recorrer[1000000];
    char r;
    int edad,i,tamano;

    if ((argc<3)||(argc>3)){
        printf("faltan argumentos");
        return 1;
    }
    entrada_name=argv[1];
    salida_mame=argv[2];

    //(1) mostrar por pantalla los archivos entregados
    printf("\nnombre de archivo de entrada\n");
    for(i=0;entrada_name[i]!=NULL;i++){
        printf("%c",entrada_name[i]);
    }
    printf("\nnombre de archivo de salida\n");
    for(i=0;salida_mame[i]!=NULL;i++){
        printf("%c",salida_mame[i]);
    }
    printf("\n");
    printf("\n");

    entrada=fopen(argv[1],"r");
    
    //(2) imprime en consola de comando el archivo de entrada
    for (i=0;fscanf(entrada,"%c",&recorrer[i])!=EOF;i++){
        printf("%c",recorrer[i]);   
    }
    fclose(entrada);
    return 0;
}
