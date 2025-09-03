#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define FULLCODE 1010101010
/*variables*/
int numCurrentElements = 0;
int QUEUESIZE;
int rear = 0;
int front = 0;
bool out2 = true;
/*VARIABLES*/
void enqueue(int val, int queue[], int queueSize);
void askEnqueueOrDequeue(int queue[]);
int dequeue(int queue[], int queueSize);
int main(){
    int *queue;
    printf("Hello, do you know how many items are going to be inside the queue?\n\nIf yes, type 1. If no, type 0 (IF YOU WANT TO GET OUT THE PROGRAM TYPE 2)\nYour input: ");
    bool out = true;
    int option;
    do{
        scanf("%d", &option);
        if(option==1){
            printf("Please type the size of the queue we are going to work with\nYour input: ");
            scanf("%d", &QUEUESIZE);
            queue = malloc(sizeof(int)*QUEUESIZE);
            out = false;
            for(int i=0;i<QUEUESIZE;i++){
                queue[i] = FULLCODE;
                /*printf("\n\n\nDATAAAA %d", queue[i]);*/
            }/*FILLING WITH FULLCODE TO DECIDE IF THE QUEUE IS FULL OR NOT*/
        }/*IF*/
        else if(option==0){
            printf("Making the size of the queue 5 by default");
            queue = malloc(sizeof(int) * 5);
            out = false;
            for(int i=0;i<5;i++){
                queue[i] = FULLCODE;
            }/*FILLING WITH FULLCODE TO DECIDE IF THE QUEUE IS FULL OR NOT*/
        }/*ELSE IF*/
        else if (option==2){
            exit(0);
        }/*ELSE IF*/
        else{
            printf("try again, please");
        }/*ELSE*/
    }while(out);
    do{
        printf("\n\nAre we going to enqueue or dequeue values?\nIf yes type 1, if no type 2 (This will get you out of the programm)\n\nYour input: ");
        scanf("%d", &option);
        if(option==1){
            askEnqueueOrDequeue(queue);
        }/*IF*/
        else if(option==2){
            exit(0);
        }/*ELSE IF*/
        else{
            printf("try again, please");
        }/*ELSE*/
    }while(out2);
    free(queue);
    return 0;
}/*MAIN*/

void askEnqueueOrDequeue(int queue[]){
    int option;
    bool end = true;
    printf("Do you want to enqueue or dequeue a value?\n\nType 1 for enqueue or 0 for dequeue\nYour option: ");
    do{
        scanf("%d", &option);
        if(option==1){
        int val;
            printf("Type in the value you want to enqueue:  ");
            scanf("%d", &val);
            enqueue(val, queue, (QUEUESIZE-1));
            end = false;
        }/*ENQUEUE*/
        else if(option==0){
            int outFront = dequeue(queue,  (QUEUESIZE-1));
            queue[outFront] = FULLCODE;
            end = false;
        }/*DEQUEUE*/
        else{
            printf("Try again, the input was not correct.");
        }/*ELSE*/
    }while(end);
}/*VOID ASK*/

void enqueue(int val, int queue[], int queueSize){
    if(rear==QUEUESIZE){
       rear = 0;
    }/*IF*/
    /*printf("DATAAAA AGAIN %d", queue[rear]);*/
    if(queue[rear]==FULLCODE){
        queue[rear] = val;
        /*printf("DATAAAA AGAIN PART 2 %d", queue[rear]);*/
        printf("\n\nThis value has entered the queue: %d at position %d\t\tSIZE OF THE QUEUE %d\n\n", val, rear, QUEUESIZE);
        for(int i=0;i<QUEUESIZE;i++){
                if(queue[i]==FULLCODE){
                    printf("\nValue inside position %d:   ", (i+1));
                }/*IF*/
                else{
                    printf("\nValue inside position %d: %d", (i+1), queue[i]);
                }/*ELSE*/
        }/*FOR*/
        rear++;
    }/*SUCCESSFUL ENQUEUE*/
    else{
        printf("\n\nWARNING. \tThe queue is full!\n\nYOUR ONLY OPTION NOW IS TO DEQUEUE");
    }/*ELSE*/    
}/*VOID ENQUEUE*/
int dequeue(int queue[], int queueSize){
    if(front==QUEUESIZE){
        front = 0;
    }/*IF*/
    int val;
    int currentFront;
    if(queue[front]!=FULLCODE){
        val = queue[front];
        currentFront = front;
        queue[front] = FULLCODE;
        printf("\nThe value from the front has been dequeued. This is the value: %d", val);
        /*printf("DATAAAA AGAIN %d", queue[front]);*/
        printf("\n\nHere are the remaining values\n");
        for(int i=0;i<QUEUESIZE;i++){
            if(queue[i]==FULLCODE){
                printf("\nValue inside position %d:  ", i);
            }/*IF*/
            else{
                printf("\nValue inside position %d: %d", (i+1), queue[i]);
            }/*ELSE*/
        }/*FOR*/
        front++;
    }/*SUCCESSFULL DEQUEUE*/
    else{
        printf("\n\nTHERE IS NO VALUE TO DEQUEUE.\n");
        for(int i=0;i<QUEUESIZE;i++){
            printf("\nValue inside position %d:  ", i);    
        }/*FOR*/
    }/*ELSE*/
    return currentFront;
}/*INT DEQUEUE*/