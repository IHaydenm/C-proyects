#include <stdio.h>
#include <stdlib.h>
int main()
{
        int rows = 3, cols = 4;
        int byteSum = 0;
        int *M = (int*)malloc(rows * sizeof(int));
        for (int i = 0; i < rows; i++) {
            M[i] = (int)malloc(cols * sizeof(int));
            printf("\nThis is the value in %d:  %d", (i+1), M[i]);
        }
        /*DEBIDO A QUE EL PROGRAMA TIENE 4 COLUMNAS Y 3 FILAS TENEMOS UN TOTAL DE 12 DATOS PARA LA MATRIZ*/
        byteSum = (12*(sizeof(int)));
         printf("\nThe bytes required for the memory are %d bytes ", byteSum);
         free(M);
         return 0;
  }