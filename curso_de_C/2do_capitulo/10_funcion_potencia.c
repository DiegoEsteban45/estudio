#include <stdio.h>

int potencia(int base, int exp);

int main(){
    int resultado,base,exponente;
    printf("base\n");
    scanf("%d", &base);
    printf("exponente\n");
    scanf("%d", &exponente);
    printf("resultado=");
    resultado=potencia(base,exponente);
    printf("%d", resultado);
    
}

int potencia(int base, int exp){
    int p,i;
    p=1;
    for(i=1;i<=exp;++i){
        p=p*base;
    } 
    return p;
    
