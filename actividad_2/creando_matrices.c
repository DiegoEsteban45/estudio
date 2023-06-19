#include <stdio.h>
#include <stdlib.h>
int main(){
    int i, j, n;
    i = 0 ;
    n = 5 ;
    j = 0 ;
    int **A;
    A=malloc(sizeof(int)*5);
    for(i=0; i<n; i++){
        A[i]=malloc(sizeof(int)*5);
        for(j=0; j<n; j++){
            A[i][j]=0;
        }
    } 
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if (j==0) {
                printf("|");
            }
            printf(" %d ",A[i][j]);
            if (j==4) {
                printf("|");
            }
        }
        printf("\n");
    }    
}
