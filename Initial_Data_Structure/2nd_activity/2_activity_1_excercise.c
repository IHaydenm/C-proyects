#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*================EJERCICIO 1=================*/
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int main(){
    /*Variables*/
    float sales[10] = {117.00, 129.95, 276.22, 564.00, 197.81, 184.80, 717.05, 325.20, 654.34, 296.56};
    float biggestNum = 0;
    int biggestNumLocation = 0;
    float tempSalesAllocation = 0;
    /*VARIABLES*/
    printf("Hello, welcome to this sales check program\n");
    /*LISTING THE VALUES OF THE SALES ARRAY*/
    for(int i=0; i<10; i++){
        bool stat = true;
        if(stat){
            printf("Index %d: value (%f) \t MEM pointer: %p \n",(i+1) ,sales[i], &sales[i]);
        }/*If brackets*/
        /*SEARCHING FOR THE BIGGEST VALUE INSIDE THE ARRAY THEN LISTING IT INSIDE THE CONSOLE*/
        if(biggestNum<=sales[i+1]){
            biggestNum = sales[i+1];
            biggestNumLocation = i+1;
                    /*if(stat){
                        printf("\nThis is the biggest value so far %f\n", biggestNum);
                        printf("\nThis is the biggest value's location %f\n", biggestNumLocation);
                    }                       THIS IF CHECKS FOR THE PROGRAMS FUNCTIONALITY USE ONLY IF NECESARY*/             
        }/*if brackets*/
        else{
            continue;
        }/*else brackets*/
    }/*for brackets*/
    printf("\nThe employe who got the biggest sales is number (%d), with a quantity of ($%f)\n", biggestNumLocation, biggestNum);
     /*LISTING THE VALUES IN AN ASCENDING ORDER*/
    int n = sizeof(sales) / sizeof(sales[0]);
    qsort(sales, n, sizeof(int), compare);
    printf("\nThis is the list of the whole list in ascendant order.\n");
    for(int k=0;k<n;k++){
        printf("\nPosition %d: $%f", (k+1), sales[k]);
    }
    return 0;
}
/*================EJERCICIO 1=================*/