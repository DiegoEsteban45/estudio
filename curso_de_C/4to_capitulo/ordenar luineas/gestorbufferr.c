#include <stdio.h>

#define ALLOCSIZE 1000000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return NULL;
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}



/*      

                              
                                ALLOCP                                              ALLOCSIZE
                                  ^                                                     ^
							      |                                                     |
                        -----------------------------------------------------------------   
	       ALLOCBUF ->  |  XXX    |              FREE                                   |
						|  XXX    |                                                     |
						-----------------------------------------------------------------
                                  
           char *alloc(int n) esta función reserva un espacio de memoria de tamaño "n" dentro del arreglo ALLOCBUF
           Ejecutamos la funcion

		   
		                 








*/                            