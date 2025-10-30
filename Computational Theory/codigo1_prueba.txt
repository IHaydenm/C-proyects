#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*node struct*/
typedef struct node{
    int data;
    struct node* next;
}Node;
/*NODE STRUCT*/

/*variables*/
bool end = true;
Node *front = NULL;
Node *rear = NULL;
int opt = 0;
/*VARIABLES*/

/*void functions*/
void enqueueList();
void dequeueList();
void seeList(int USE);
void autoFill();
/*VOID FUNCTIONS*/

int main(){
    int USE = 0;
    printf("\n\nWelcome!\t This program makes queues using lists\n\nWe have created a list for 5 values, but you can always insert more values to the list");
    autoFill();
    do
    {
        printf("\n\nPress '1' to enqueue a value.\nPress '2' to dequeue a value.\nPress '3' to see the list.\nPress '4' to exit the program\n\nYour input:  ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        USE = 0;
            enqueueList();
            seeList(USE);
            break;
        case 2:
        USE = 0;
            dequeueList();
            seeList(USE);
            break;
        case 3:
        USE = 1;
            seeList(USE);
            break;
        case 4:
            end = false;
            break;
        default:
            printf("\n\nThe input was not valid, try again please!");
            break;
        }
    } while (end);
    return 0;
}//MAIN
void autoFill(){
    int i=0;
    int val[5]={45,65,488,54,21};
    while(i<5){
    Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode != NULL){
            //memoria válida para asignar el int y el siguiente puntero
            //1. inicializando el nodo
            newNode -> data = val[i];
            newNode -> next = NULL;
            //2. agregando el nodo a la lista
            //2.1 si la lista está vacía, este es el primer nodo
            if(front == NULL){
                front = newNode;
                rear = newNode;
            }
            else
            {
            //2.2 Localizamos el ultimo nodo de la lista
                Node *aux = front;
                while (aux->next != NULL) aux = aux->next;
                //2.3 agregamos el nuevo nodo
                aux->next = newNode;
                rear = aux -> next;
            }
        }
        i++;
    }//WHILE i<4
}//AUTOFILL VOID
void enqueueList(){
    Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode != NULL){
            //memoria válida para asignar el int y el siguiente puntero
            //1. inicializando el nodo
            int val;
            printf("\nPlease write the number: ");
            scanf("%d", &(newNode->data));  newNode->next = NULL;
            //2. agregando el nodo a la lista
            //2.1 si la lista está vacía, este es el primer nodo
            if(front == NULL){
                front = newNode;
                rear = newNode;
            }
            else
            {
            //2.2 Localizamos el ultimo nodo de la lista
                Node *aux = front;
                while (aux->next != NULL) aux = aux->next;
                //2.3 agregamos el nuevo nodo
                aux->next = newNode;
                rear = aux -> next;
            }
        }
}
void dequeueList(){
    if(front == NULL){
        printf("\n\nThe list is empty!\t You will have to enqueue first in order to dequeue.");
        
    }
    else{
        printf("\n\nThe value will be shortly dequeued");
        printf("\n\nThe value in the front is %d\n", (front -> data));
        Node *aux = front;
        front = front -> next;
        free(aux);
        if(front==NULL){
            rear == NULL;
        }//THIS HAPPENS ONLY IF THE FRONT ELIMINATES THE ONLY NODE REMAINING FROM THE LIST; THEN REAR WILL ALSO HAVE TO BECOME NULL
    }/*DEQUEUE*/
}//DEQUEUE
void seeList(int USE){
    if(front == NULL && USE == 1){
        printf("\n\nThe list is empty!\t You will have to enqueue some value first!");
    }/*IF THE LIST IS EMPTY*/
    else{
        Node *aux = front;
        int i = 1;
        while(aux != NULL){   
            printf("\nThe value inside %d, %d", i, aux -> data);
            i++;
            aux = aux -> next;
        }
        printf("\n\nThe display of the list has ended with showing %d different nodes", (i-1));  
    }//THE LIST HAS VALUES INSIDE
}
