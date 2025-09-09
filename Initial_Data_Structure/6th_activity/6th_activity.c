#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define EMPTYKEY 1010101010
/*variables*/
bool out = true;
int option;
bool end = true;
int top = 0;
int inValue = 0;
/*VARIABLES*/

int pop (int stack[]);
bool isEmpty(int stackVal);
void push(int stack[], int value, int stackSize);
bool isFull(int stackSIZE);
int Peek(int stack[]);
int main(){
  int *stack;
  int stackSIZE;
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
      stackSIZE = 5;
      printf("Making the size of the stack 5 by default");
      stack = malloc(sizeof(int) * stackSIZE);
      for(int i=0; i<stackSIZE; i++){
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
    printf("\n\n(IF YOU WANT TO GET OUT THE PROGRAM TYPE 10)\n\nWould you like to POP, PUSH, or get to know the LAST VALUE inserted into the stack?\n\n1. POP\n2. PUSH\n3. SEE LAST VALUE\n\nType the number behind the option you want to select: ");
    scanf("%d", &option);
    switch (option){
    case 1:
        printf("\nPopping the last value...\nThe value inside was %d", pop(stack));
      break;
    case 2:
        printf("Please, type in the value you want to push into the stack.\n\nValue: ");
        scanf("%d", &inValue);
        printf("\nPushing the value inside the stack...\n");
        push(stack, inValue, stackSIZE);
      break;
    case 3:
        printf("The last value that entered the stack is: %d", Peek(stack));
      break;
    case 10:
        printf("EXITING");
        exit(0);
      break;
    default:
        printf("\nThere has been an error while introducing an expected value, please try again.\n");
      break;
    }
  }while(end);
  free(stack);/*FREEING THE MALLOC MEM OF stack*/
  return 0;
}/*MAIN*/
int pop(int stack[]) {
  int stackVal;
  stackVal = stack[top-1];
  bool checkEmpty;
  checkEmpty = isEmpty(stackVal);
  if (checkEmpty) {
    printf("Sorry, the stack is trully empty :(\n");
    return -1; /* Código de error*/
  }
  else {
    if(top>=0){
      top--;
      int value = stack[top];
      stack[top] = EMPTYKEY;
      return value;
    }
    else{
      top = 0;
    }
  }
}/*POP*/
void push(int stack[], int value, int stackSize){
  int tempStackSize = stackSize;
  bool checkFull;
  checkFull = isFull(tempStackSize);
  if(checkFull){
    printf("Sorry, the stack is trully full D: !\n\nTry popping a value now");
  }
  else {
    stack[top] = value;
    top++;
    printf("Element %d inserted.\n", value);
  }
}/*PUSH*/
int Peek(int stack[]){
  int seeValue;
  seeValue = stack[top-1];
  return seeValue;
}
bool isFull(int stackSize){
  int tempStackSize = stackSize;
  bool isItFull = false;
  if(top == tempStackSize){
    isItFull = true;
  }
  else{
    isItFull = false;
  }
  return isItFull;
}/*THIS WILL DECLARE IF THE STACK IS FULL OR NOT*/

bool isEmpty(int stackVal){
  bool isItEmpty = false;
  int tempStackVal = 0;
  tempStackVal = stackVal;
  if(tempStackVal==EMPTYKEY){
    isItEmpty = true;
  }
  else{
    isItEmpty = false;
  }
  return isItEmpty;
}/*THIS WILL DECLARE IF THE STACK IS EMPTY OR NOT*/