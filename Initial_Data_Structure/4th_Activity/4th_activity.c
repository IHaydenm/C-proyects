#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void spiralCounter();
/*Variables*/
int arr[5][4] =  {{1, 2, 3, 4}, {14, 15, 16, 5}, {13, 20 ,17, 6}, {12, 19, 18, 7}, {11, 10, 9, 8}}; 
/*VARIABLES*/
int main(){
    for(int i=0; i<5; i++){
        printf("\n");
        for(int j=0;j<4;j++){
            printf("\tValue of index [%d][%d] = %d", i, j, arr[i][j]);
        }
    }
    printf("\n\nThe values inside the matrix will be displayed in a spiral manner momentarlly...\n");
    spiralCounter();
    return 0;
}
void spiralCounter(){
    bool end = true;
    int i = 0;
    int j = 0;
    int counter = 1;
    do{
        if((i==0) && (j==0)){
            while(j<3){
                printf("\nVariable %d = %d", counter, arr[i][j]);
                j++;
                /*printf("VAL OF J %d", j); test*/
                counter++;
            }
        }/*This will give the contents of row fixed in 0 and columns 0 to 3*/
        if((i==0) && (j==3)){
            while(i<5){
                printf("\nVariable %d = %d", counter, arr[i][j]);
                /*printf("VAL OF i %d", i); test*/
                i++;
                counter++;
            }
            /*printf("i %d, j %d", i, j);*/
            i--;
        }/*This will give us the contents of rows 0 to 4 and column fixed in 3*/
        if((i==4) && (j==3)){
            j--;
            while(j>-1){
                printf("\nVariable %d = %d", counter, arr[i][j]);
                j--;
                counter++;
            }
            j++;
            /*printf("i %d, j %d", i, j);*/
        }/*This will give us the contents of row fixed in 4 and columns 3 to 0*/
        if((i==4) && (j==0)){
            i--;
            /*printf("i %d, j %d", i, j);*/
            while(i>0){
                printf("\nVariable %d = %d", counter, arr[i][j]);
                i--;
                counter++;
            }
            i++;
            /*printf("i %d, j %d", i, j);*/
        }/*This will give us the contents of rows 4 to 1 and column fixed in 0*/
        if((i==1) && (j==0)){
            j++;
            /*printf("i %d, j %d", i, j);*/
            while(j<3){
                printf("\nVariable %d = %d", counter, arr[i][j]);
                j++;
                counter++;
            }
            j--;
            /*printf("i %d, j %d", i, j);*/
        }/*This will give us the contents of row fixed in 1 and columns 0 to 2*/
        if((i==1) && (j==2)){
            i++;
            while(i<4){
                printf("\nVariable %d = %d", counter, arr[i][j]);
                i++;
                counter++;
            }
            /*printf("i %d, j %d", i, j);*/
            i--;
        }/*This will give us the values of the rows 1 to 3 and column fixed in 2*/
        if((i==3) && (j==2)){
            j--;
            while(j>0){
                printf("\nVariable %d = %d", counter, arr[i][j]);
                j--;
                counter++;
            }
            j++;
            /*printf("i %d, j %d", i, j);*/
        }/*This will give us the contents of row fixed in 3 and columns 2 and 1*/
        if((i==3) && (j==1)){
            i--;
            printf("\nVariable %d = %d", counter, arr[i][j]);
            end = false;
        }/*This will give us the final value inside the matrix at row 2 and column 1*/
    }while(end);
    printf("\n\nTHE ALGORITHM HAS ENDED");
}