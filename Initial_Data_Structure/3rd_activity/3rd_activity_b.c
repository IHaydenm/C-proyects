/*==================EJERCICIO 2=================*/
#include <stdlib.h>
#include <stdio.h>
/*variables*/
    int X = 0;
    int Y = 0;
    int tempChange = 0;
    int *ptrForChange = &tempChange;
    int *ptrforX;
    int *ptrforY;
    /*VARIABLES*/
void CheckValues(){
    printf("\n\nValue of the X location: %p\n ", &X);
    printf("Value of the Y location: %p\n ", &Y);
    printf("Value of the X location through its pointer: %p\n ", ptrforX);
    printf("Value of the Y location through its pointer: %p\n ", ptrforY);
}
int main(){
    printf("This code will exchange values of two variables 'A' and 'B' only through their memory location\n\n");
    printf("Please write the value of variable A: ");
    scanf("%d", &X);
    printf("Please write the value of variable B: ");
    scanf("%d", &Y);
    ptrforX = &X;
    ptrforY = &Y;
    CheckValues();
    printf("\nDown below will be displayed the values of the variables before change:\n\nValue of the allocated value in &X: %d", *ptrforX);
    printf("\nValue of the allocated value in &Y: %d\n\nThe exanged values will be displayed momentarlly", *ptrforY);
    *ptrForChange = *ptrforX;
    *ptrforX = *ptrforY;
    *ptrforY = *ptrForChange;
    printf("\n\nValue of the allocated value in &X: %d\nValue of the allocated value in &Y: %d", *ptrforX, *ptrforY);
    CheckValues();
    return 0;
}
/*==================EJERCICIO 2=================*/