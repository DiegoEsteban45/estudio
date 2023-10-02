#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE* archivo;
	FILE* archivoS;
	
	/*--- lectura de archivo ---*/
	archivo=fopen(argv[1],"r"); /* leectura del primer archivo escrito en la consola*/

	int filas, columnas, valor;
	
	fscanf(archivo,"%d",&filas);
	fscanf(archivo,"%d",&columnas);

	printf("Los primeros valores son: %d y %d\n",filas,columnas);

	/*--- escritura de archivo ---*/
	archivoS=fopen("Salida.txt","w");

	int i,j;

	for (i=0;i<filas;i++)
	{
		for (j=0;j<columnas;j++)
		{	
			fscanf(archivo,"%d",&valor);
			printf("%d ",valor);
			fprintf(archivoS,"%d ",valor);
		}
		printf(" \n");
		fprintf(archivoS,"\n");
	}
	fclose(archivo);
	fclose(archivoS);

	return 0;
}
