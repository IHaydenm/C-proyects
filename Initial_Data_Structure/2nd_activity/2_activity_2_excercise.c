#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*================EJERCICIO 2=================*/
int compare(const void* a, const void* b){
    return (*(int*)b - *(int*)a);
}
int main(){
    /*Variables*/
    int calArr[10];
    int inpTypeCheck;
    int i=0;
    int tempCalArr = 0;
    int limit = 9;
    int fullAdd = 0;
    int totalAvg = 0;
    bool out = true;
    /*VARIABLES*/
    printf("\nWelcome to this new grading system for school courses.");
    /*READING THE INPUTS FOR THE STUDENT'S GRADES*/
    do{
        printf("\nPlease write the student with number %d, grade (from 0 to a 100): ", (i+1));
        scanf("%d", &tempCalArr);
        if(tempCalArr<=100){
            if(i==limit){
                out = false;
            }
            calArr[i] = tempCalArr;
            i++;
            tempCalArr = 0;
        }
        else{
            printf("Try again, please.");
            tempCalArr = 0;
        }
    }while(out);
    printf("The average grade of the class will now be calculated.");
    for(int j=0;j<10;j++){
        fullAdd = calArr[j] + fullAdd;
        /*printf("\nThis are the contents within %d: %d", j, calArr[j]);*/
        totalAvg = fullAdd/((sizeof(calArr)/sizeof(calArr[0])));
    }
    /*printf("\nThis is the full addition of the grades: %d", fullAdd);*/  
    printf("\nThe average grade of the class is: %d", totalAvg);
     /*LISTING THE VALUES IN AN ASCENDING ORDER*/
    int n = sizeof(calArr) / sizeof(calArr[0]);
    qsort(calArr, n, sizeof(int), compare);
    printf("\nThis is the list of the whole list in descendant order.\n");
    for(int k=0;k<n;k++){
        printf("\nPosition %d: %d", (k+1), calArr[k]);
    }
    return 0;
}
/*================EJERCICIO 2=================*/