#include <stdio.h>
main(){  
    int c,i,nwhite,nother;
    int ndigit[10];
    
    for (i = 0; i < 10; i++){
        ndigit[i]=0;         //array [0,0,0,0,0,0,0,0,0,0]
    }
    nwhite=nother=0;
    while((c=getchar())!=EOF){
        if(c>='0'&&c<='9'){
            ++ndigit[c-'0'];                   // c es una variable de tipo int que almacenara un caracter a la ves debido a la funcion getchar
        }                                     // por lo tanto se usa la exprecion c-'0' para restar cararcteres numericos, cada caracter numerico del 0-9
                                             // tiene un valor asociado de la tabla ASCII ej el '0' vale 48 y el '1' 49 por lo tanto si restas
                                            // ambos caracteres numericos el resultado es 1, segundo ejemplo '0'-'9'= ASCII(48-57) = 9. 
        else if (c==' '||c=='\n'||c=='\t'){
            ++nwhite;
        }
        else{
            ++nother;
        }
    }
    printf("[0,1,2,3,4,5,6,7,8,9]\n"); 
    printf("[^ ^ ^ ^ ^ ^ ^ ^ ^ ^]\n");
    printf("[");
    for (i = 0; i < 10; i++){
        if (i<9)
            printf("%d,", ndigit[i]);
           
        else if (i==9)
            printf("%d", ndigit[i]);                    
    }
    printf("]");
    printf("\n");
    printf("espacios blancos=%d, otros=%d\n", nwhite, nother);
}

