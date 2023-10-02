/**BIBLIOTECAS.**/
#include <stdio.h>		//Biblioteca de funciónes básicas de C.
#include <stdlib.h>		//Biblioteca de asignación de memoria de C.

//VARIABLES GLOBALES.
/*En este caso no se requieren, se puede omitir.*/

/**ESTRUCTURAS.**/

//Lista.
typedef struct Lista
{
	int *lista;		//Puntero a estructura entero.
	int tam;		//Tamaño de la lista.
}Lista;

/**FUNCIONES SECUNDARIAS.**/

/**
 * Entrada: Tamaño de lista.
 * Salida: Lista.
 * Descripción: Función que crea el TDA lista.
*/
Lista crearLista(int Tam)
{
	//VARIABLES INTERNAS.
	Lista Salida;		//Lista a crear.

	//PROCESAMIENTO.
	//Se reserva espacio en memoria a la lista y
	//se establece tamaño.
	Salida.lista = (int*)malloc(sizeof(int)*Tam);
	Salida.tam = Tam;

	//Se devuelve lista.
	return Salida;
}

/**
 * Entrada: Lista. 
 * Salida: void.
 * Descripción: Se muestra arreglo.
*/
void MostrarLista(Lista Entrada)
{
	//VARIABLES INTERNAS.
	int i;				//Contador para recorrido.

	//PROCESAMIENTO.
	printf("[");
	for (i=0; i < Entrada.tam ;++i)
	{
		if (i < (Entrada.tam-1))
		{
			printf("%i, ",Entrada.lista[i]);
		}

		else
		{
			printf("%i]\n",Entrada.lista[i]);
		}
	}
}

/**
 * Entrada: Lista y entero.
 * Salida: void.
 * Descripción: Busqueda lineal.
*/
void BusquedaLineal(Lista Entrada, int* objetivo)
{
	//VARIABLES INTERNAS.
	int i;				//Contador para recorrido.

	//PROCESAMIENTO.
	for (i=0; i < Entrada.tam ;++i)
	{
		if (Entrada.lista[i] == *objetivo)
		{
			printf("El numero %i se encuentra en el arreglo.\n",*objetivo);
			return;
		}
	}

	printf("El numero %i no se encuentra en el arreglo.\n",*objetivo);
}

/**
 * Entrada: entero y entero. 
 * Salida: void.
 * Descripción: función de intercambio.
*/
void swap(int* A, int* B)
{
	//VARIABLES INTERNAS.
	int Aux;			//Auxiliar de apoyo para intercambio.

	//PROCESAMIENTO.
	//Aquí lo que se realiza no es cambiar el valor de A, sino
	//se cambia el valor almacenado dentro de puntero A.
	Aux = (*A);
	(*A) = (*B);
	(*B) = Aux;

	//FINALIZACIÓN.
	return;
}

/**
 * Entrada: Lista. 
 * Salida: void.
 * Descripción: Ordenamiento burbuja.
*/
void BubbleSort(Lista *Entrada)
{
	//VARIABLES INTERNAS.
	int i;				//Contadores para recorrido.
	int j;

	//PROCESAMIENTO.
	
	//Recorrido de verificación 1.
	for (i=0; i<Entrada->tam ;++i)
	{
		//Recorrido de verificación 2.
		for (j=0; j<Entrada->tam ;++j)
		{
			if(Entrada->lista[i] < Entrada->lista[j])
			{
				swap(&Entrada->lista[i], &Entrada->lista[j]);
			}
		}
	}

	//FINALIZACIÓN.
	return;
}

/**FUNCION PRINCIPAL**/
int main(int argc, char *argv[])
{
	//VARIABLES INTERNAS.
	FILE* fp;			//Puntero de recorrido de archivo de entrada.
	FILE* fpo;			//Puntero de recorrido de archivo de salida.
	Lista Prueba;		//Instancia de estructura Lista.
	int TamArray;		//Variable que almacena largo del arreglo.
	char* FileName;		//Variable que guarda el nombre del archivo.
	int i;				//Contador de proposito general.
	int Aux;			//Auxiliar de proposito general.
	int entero;			//Variable que representa entero objetivo a buscar.

	//ENTRADA.

	//No hay nombre de archivo.
	if(argc < 2)
	{
		//Mensaje de retroalimentación.
		printf("No se entrego nombre del archivo.\n");

		//Retorno.
		return 0;
	}

	//Existencia de archivo.
	FileName = argv[1];
	fp = fopen(FileName,"r");
	if(fp == NULL)
	{
		//Mensaje de retroalimentación.
		printf("%s\n","El archivo dado no existe.");

		//Retorno.
		return 0;
	}

	//PROCESAMIENTO.

	//Obtener tamaño del arreglo.
	fscanf(fp, "%i\n", &TamArray);

	//Generar arreglo dinámico.
	Prueba = crearLista(TamArray);

	//Insersión de elementos.
	i = 0;
	while(fscanf(fp, "%i\n", &Aux) != EOF)
	{
		Prueba.lista[i] = Aux;
		i++;
	}

	//Cierre de archivo de entrada.
	fclose(fp);

	//Se muestra primera lista.
	printf("\n%s\n","Lista desordenada:");
	MostrarLista(Prueba);

	//Algoritmo de búsqueda.
	
	/**Entrada.**/
	printf("\nEscriba un n%cmero entero a b%cscar en el arreglo: ",163,163);
	scanf("%i", &entero);

	/**Funcion**/
	BusquedaLineal(Prueba, &entero);

	//Algoritmo de ordenamiento.

	/**Funcion**/
	BubbleSort(&Prueba);

	//Se muestra lista final.
	printf("\nLista ordenada ascendentemente:");
	MostrarLista(Prueba);

	//SALIDA.
	
	//Apertura
	fpo = fopen("OUTPUT.doc","w");

	//Escritura.
	for (i=0; i<Prueba.tam ;++i)
	{
		fprintf(fpo, "%i\n", Prueba.lista[i]);
	}

	//Cierre.
	fclose(fpo);

	return 0;
}