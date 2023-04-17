#include <stdio.h>

int main() {
    char c;
    printf("Ingrese varios caracteres: ");
    while ((c = getchar()) != '\n') {
        printf("El caracter ingresado es: %c\n", c);
    }
    return 0;
}