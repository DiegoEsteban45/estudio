#include <stdio.h>
int binarisearch(int num,int array[],int len){
    int lim_inf, lim_sup, mid;
    lim_inf=0;
    lim_sup=len-1;
    while (lim_inf<=lim_sup){
        mid=(lim_inf+lim_sup)/2; //sera el indice que indique del elemnto que se encuntre a la mitad del arreglo
        if (num<array[mid])
            lim_sup=(mid-1);
        else if (num>array[mid])
            lim_inf=(mid+1);
        else 
            return mid;
    }
    return -1; 
       
}
int main(){
    int n,l,elemento_a_buscar,i;
    int a[]={23,56,78,90,98,455,3333,67767,100000};
    l=9;
    n=0;
    elemento_a_buscar=-1;
    elemento_a_buscar=binarisearch(n,a,l);
    printf("{");
    for (i=0;i<=(l-1);i++){
        printf("%d,",a[i]);
    }
    printf("}\n");
    if (elemento_a_buscar==-1)
        printf("no esta"); 
    else
        printf("el numero %d se encontro en la posicion %d",n,(elemento_a_buscar+1));
}
