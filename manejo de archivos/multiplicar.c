#include <stdio.h>		//Biblioteca de funciónes básicas de C.
#include <stdlib.h>	


int main(int argc, char const *argv[]){

    FILE* MATRIZ_1;
    FILE* MATRIZ_2;
    FILE* RESULTADO;
    FILE* ejemplo;
    int **matriz_1;
    int **matriz_2;
    int **producto;
    int pos_1,pos_2,pos_pro,result,fila_1,fila_2,colum_1,colum_2,i,j,k,count;

    if ((argc<3)||(argc>3)){
        printf("\nERROR: INDIQUE CORRECTAMENTE LOS ARCHIVOS.\n");
        printf("\nejemplo:\nenrrutado...\\carpeta>multiplicar.exe a.txt b.txt\n");
        return 1;
    }

    MATRIZ_1=fopen(argv[1],"r");
    MATRIZ_2=fopen(argv[2],"r");

    if ((MATRIZ_1 == NULL)&&(MATRIZ_2 == NULL)) {
        printf("\nERROR: ARCHIVO(S) NO ENCONTRADO(S)\n");
        printf("asegurese que la ubicacion o formato del archivo de texto sea el correcto para operar\nejemplo:\n");
        printf("(numero de filas->3)  (numero de columnas->3)\n");
        printf("1 2 3\n4 5 6\n7 8 9\nrevise el archivo ejemplo.txt creado\n");
        printf("Nota: el orden de matrices a multiplicar tiene que tener el mismo numero de columnas que el de filas\n");
        ejemplo=fopen("ejemplo.txt","w");
        count=1;
        fprintf(ejemplo,"%d ",3);
        fprintf(ejemplo,"%d ",3);
        fprintf(ejemplo,"\n"); 
        for (i=0; i<3; i++){
            for (j=0; j<3; j++){
                fprintf(ejemplo,"%d ",count);
                count++;      
            }
            fprintf(ejemplo,"\n");
        }
        
        fclose(ejemplo);
        return 1;
    }

    fscanf(MATRIZ_1,"%d",&fila_1);
    fscanf(MATRIZ_1,"%d",&colum_1);
    fscanf(MATRIZ_2,"%d",&fila_2);
    fscanf(MATRIZ_2,"%d",&colum_2);

    if (colum_1 != fila_2){
        printf("\nERROR: MATRICES INCOMPATIBLES PARA OPERAR\n");
        printf("asegurese que el formato del archivo de texto sea el correcto para operar\nejemplo:\n");
        printf("(numero de filas->3)  (numero de columnas->3)\n");
        printf("1 2 3\n4 5 6\n7 8 9\nrevise el archivo ejemplo.txt creado\n");
        printf("Nota: el orden de matrices a multiplicar tiene que tener el mismo numero de columnas que el de filas\n");
        ejemplo=fopen("ejemplo.txt","w");
        count=1;
        fprintf(ejemplo,"%d ",3);
        fprintf(ejemplo,"%d ",3);
        fprintf(ejemplo,"\n"); 
        for (i=0; i<3; i++){
            for (j=0; j<3; j++){
                fprintf(ejemplo,"%d ",count);
                count++;      
            }
            fprintf(ejemplo,"\n");
        }
        
        fclose(ejemplo);
        return 1;
    }
    RESULTADO=fopen("resultado.txt","w");
    /*a las matrices les asignamos la memoria correspondiente */

    //matriz 1
    matriz_1=malloc(sizeof(int)*fila_1);
    for(i=0;i<fila_1;i++){
        matriz_1[i]=malloc(sizeof(int)*colum_1);
    }
    //matriz 2
    matriz_2=malloc(sizeof(int)*fila_2);
    for(i=0;i<fila_2;i++){
        matriz_2[i]=malloc(sizeof(int)*colum_2);
    } 
    //producto
    producto=malloc(sizeof(int)*fila_1);
    for(i=0;i<fila_1;i++){
        producto[i]=malloc(sizeof(int)*colum_2);
    }

    //asignamos los valores a MATRIZ_1 y mostarmos por pantalla
    printf("matriz_1\n");
    for (i=0; i<fila_1; i++){
        for (j=0; j<colum_1; j++){
            fscanf(MATRIZ_1,"%d",&pos_1);
            matriz_1[i][j]=pos_1;
            printf(" %d ",matriz_1[i][j]);
        }
        printf("\n");

    }
    printf("\nmatriz_2\n");
    //asignamos los valores a MATRIZ_2 y mostramos por pantalla
     for (i=0; i<fila_2; i++){
        for (j=0; j<colum_2; j++){
            fscanf(MATRIZ_2,"%d",&pos_2);  
            matriz_2[i][j]=pos_2;
            printf(" %d ",matriz_2[i][j]); 
        }
        printf("\n");

    }
    printf("\nproducto matricial\n");
    //multiplicacion de matrices
    pos_pro=0;
    for (i=0; i<fila_1; i++){ // nos movemos por las filas de matriz_1
        for(k=0;k<colum_2;k++){ //nos movemos por las columnas de la matriz_2
            for(j=0;j<fila_2;j++){ //nos movemos por las columnas de la matriz_1 y por las filas de la matriz_2
                pos_pro=pos_pro+(matriz_1[i][j]*matriz_2[j][k]);
            }
            producto[i][k]=pos_pro;
            pos_pro=0;
        }
    }
    //mostramos el resultado de la multiplicacion y escribimos el resultado en resultado.txt
    fprintf(RESULTADO,"%d ",fila_1);
    fprintf(RESULTADO,"%d ",colum_2);
    fprintf(RESULTADO,"\n"); 
    for (i=0; i<fila_1; i++){
        for (j=0; j<colum_2; j++){
            printf(" %d ",producto[i][j]);
            fprintf(RESULTADO,"%d ",producto[i][j]);      
        }
        printf("\n");
        fprintf(RESULTADO,"\n"); 
    }
    fclose(RESULTADO);
    fclose(MATRIZ_1);
    fclose(MATRIZ_2);
    free(matriz_1);
    free(matriz_2);
    free(producto);

    return 0;

}
