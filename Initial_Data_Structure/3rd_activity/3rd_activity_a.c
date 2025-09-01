#include <stdio.h>
#include <stdlib.h>
int main() {
    int numero = 10;
    int *puntero;
    puntero = &numero; // puntero apunta a la dirección de numero
    printf("Valor de numero: %d\n", numero);
    printf("Direccion de numero: %p\n", &numero);
    printf("Valor almacenado en puntero (direccion): %p\n", puntero);
    printf("Valor al que apunta el puntero: %d\n", *puntero);
    // Cambiando el valor de numero a través del puntero
    *puntero = 20;
    printf("Nuevo valor de numero: %d\n", numero);
    return 0;
}