#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define EMPTYKEY 1010101010
/*variables*/
bool out = true;
int option;
int stackSIZE;
bool end = true;
/*VARIABLES*/
int pop (int stack[]);
int main(){
    int *stack;
    printf("Hello, welcome to this stacks test program.\n\n");
    do{
        printf("\nDo you know how many items will be allowed into your stack?\n\nType 1 for YES | Type 0 for NO. | (IF YOU WANT TO GET OUT THE PROGRAM TYPE 2)\n\nYour input: ");
        scanf("%d", &option);
        if(option==1){
            printf("\nPlease, type in the size of the stack: ");
                scanf("%d", &stackSIZE);
                stack = malloc(sizeof(int) * stackSIZE);
                printf("Making the size of the stack %d.", stackSIZE);
            for(int i=0; i<stackSIZE; i++){
                    stack[i] = EMPTYKEY;
                    /*printf("DATA %d: %d", (i+1), stack[i]);*/
            }/*FILLING IN WITH AN IDENTIFIER TO KNOW WHERE A SPACE IS EMPTY WITH A FOR CYCLE*/
            out = false;
        }/*THIS IF WILL ASK FOR THE SIZE OF THE stack NEEDED TO WORK WITH IN THIS PROGRAM*/
        else if(option==0){
            printf("Making the size of the stack 5 by default");
            stack = malloc(sizeof(int) * 5);
            for(int i=0; i<5; i++){
                stack[i] = EMPTYKEY;
                /*printf("DATA %d: %d", (i+1), stack[i]);*/
            }/*FILLING IN WITH AN IDENTIFIER TO KNOW WHERE A SPACE IS EMPTY WITH A FOR CYCLE*/
            out = false;
        }/*THIS ELSE IF WILL CREATE A stack THE SIZE OF 5*/
        else if(option==2){
            exit(0);
        }
        else{
            printf("\nTry again please, the input was invalid.");
        }/*THIS ELSE WILL KEEP THE CYCLE GOING IF THE INPUT IS DIFFERENT THAN 1 OR 0*/
    }while(out);/*THIS DO WHILE CYCLE WILL BE NEEDED TO CREATE THE INITIAL stack*/
    do{
        printf("\n\nWould you like to POP, PUSH, or get to know the LAST VALUE inserted into the stack?\n\n1. POP\n2. PUSH\n 3. SEE LAST VALUE\n\nType the number behind the option you want to select: "); 
        scanf("%d", &option);
        switch (option){
        case 1:
            print("Popping the last value...");

            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
    }while(end);
    free(stack);/*FREEING THE MALLOC MEM OF stack*/
    return 0;
}/*MAIN*/

int pop() {
    if (isEmpty()) {
    printf("Error: La pila está vacía.\n");
    return -1; // Código de error
    } else {
    int value = stack[top];
    top--;
    return value;
    }
}