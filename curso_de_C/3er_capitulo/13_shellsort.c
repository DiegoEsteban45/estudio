#include <stdio.h>

void shellshort(int v[],int n);

int main(){
    int i;
    int lista_desordenada[]={3,1,675,90,6,120,469,220,875}; 

    /*busqueda binaria*/
    shellshort(lista_desordenada,9);

    for(i=0;i<9;++i) printf("%d ",lista_desordenada[i]);
}
/*shellshort: ordena v[]*/
void shellshort(int v[],int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2)
        for(i=gap;i<n;i++)  
            for(j=i-gap;(j>=0)&&(v[j]>v[j+gap]);j=j-gap){ 
                printf("%d j\n",j);    
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;  
            }
}
