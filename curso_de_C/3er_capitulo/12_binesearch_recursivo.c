#include <stdio.h>
#define LARG 1000
int p_array_int(int *array){
    while (*array!=NULL){
           printf("%d,",*array);
           array++;
    }
}
int binarisearchr(int num,int array[],int lim_inf,int lim_sup,int mid){
    mid=(lim_inf+lim_sup)/2;
    if (array[mid]==num){
        return mid;
    }else if (lim_inf==mid||lim_sup==mid){
        return -1;
    }else if (num<array[mid]){
        lim_sup=(mid-1);
        return binarisearchr(num,array,lim_inf,lim_sup,mid); //POR LA IZQUIERDA 
    }else if (num>array[mid]){
        lim_inf=(mid+1);
        return binarisearchr(num,array,lim_inf,lim_sup,mid); //POR LA DERECHA
    }  
}
void shellshort(int v[],int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2)
        for(i=gap;i<n;i++)  
            for(j=i-gap;(j>=0)&&(v[j]>v[j+gap]);j=j-gap){     
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;  
            }
}
int main(){
    int n,l,elemento_a_buscar,i,L_I,L_S,MID,c,nums;
    int a[LARG];
    printf("ingrese un numero y -1 para terminar\n");
    c=0;
    scanf("%d",&nums);
    a[c]=nums;
    c++;
    while (nums!=-1){
        printf("ingrese un numero y -1 para terminar\n");
        scanf("%d",&nums);
        a[c]=nums;
        c++;
    }
    l=(c-1);
    shellshort(a,l);
    printf("numero a buscar\n");
    scanf("%d",&n); // numero a buscar 
    L_I=0;
    L_S=(l-1);
    elemento_a_buscar=binarisearchr(n,a,L_I,L_S,MID);
    a[l]=NULL;
    printf("{");
    p_array_int(a);
    printf("}\n");
    if (elemento_a_buscar==-1)
        printf("no esta %d en el arreglo",n); 
    else
        printf("el numero %d se encontro en la posicion %d\n",n,(elemento_a_buscar+1));
}





