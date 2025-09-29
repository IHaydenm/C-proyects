#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* before;
}Node;
/*variables*/
Node* head;
bool end = true;
/*VARIABLES*/
void showModules();
void owFirstModule();
void owModule(int pos);
void elimNode();
void showPrevVal();
int main(){
    head = NULL; int ans = 0;
    do{
        printf("\n\nPress '0' to create a new node and add a new value to the list\nPress '1' to see al the values inside the already created nodes\nPress '2' to write inside the first node (WARNING THIS WILL OVERWRITE THE NODE)\nPress '3' to write inside a specific node (WARNING THIS WILL OVERWRITE THE NODE)\nPress '4' to eliminate a specific node\nPress '5' to know the previous value from a given node position.\nPress '101010' to exit the program\n\nYour Selection: ");
        scanf("%d", &ans);
        switch (ans){
            case 0:
                //creando el nuevo nodo
                Node *newNode = (Node*)malloc(sizeof(Node));
                if (newNode != NULL){
                    //memoria válida para asignar el int y el siguiente puntero
                    //1. inicializando el nodo
                    int val;
                    printf("Please write the number: ");
                    scanf("%d", &(newNode->data));  
                    //2. agregando el nodo a la lista
                    //2.1 si la lista está vacía, este es el primer nodo
                    if(head == NULL){
                        newNode->before = NULL; //MAKING THE BEFORE HEAD NULL | READY TO RECIEVE THE LAST NODE POSITION
                        newNode->next = NULL; //MAKING THE NEXT NULL | READY TO RECIEVE NEXT NODE
                        head = newNode; //MAKING THE NEWNODE ENTER INSIDE HEAD 
                    }
                    else
                    {
                        //2.2 Localizamos el ultimo nodo de la lista
                        Node *aux = head;
                        while (aux->next != NULL) aux = aux->next;
                        //2.3 agregamos el nuevo nodo
                        aux->next = newNode;//This will create a new node in front of aux
                        newNode->before = aux;//We'll atribute newNode in the previous position = aux;
                    }
                }
                break;
            case 1: 
                showModules();
                break;
            case 2:
                owFirstModule();
                break;
            case 3:
                int pos = 0;
                printf("\n\nPlease, specify the node you want to modify: ");
                scanf("%d", &pos);
                if(pos>0){
                    owModule(pos);
                }
                else{
                    printf("\n\nThe input was invalid because it was not a number greater than 0, please try again");
                }
                break;
            case 4: 
                elimNode();
                break;
            case 5:
                showPrevVal();
                break;
            case 101010://OUT PROGRAM CONDITION
                end = false;
                break;
        default:
            printf("\n\nThe input value was not a valid one! \tPLEASE TRY AGAIN");
            break;
        }
    } while(end); //do
} //main


void showModules(){
    if(head == NULL){
        printf("\n\nThe list is empty!");
    }
    Node *aux = head;
    int i = 1;
    while(aux != NULL){   
        if(i==1){
            printf("\nThe value inside %d, %d  FIRST NODE", i, aux -> data);    
        }
        else if((aux->next)==NULL){
            printf("\nThe value inside %d, %d  LAST NODE", i, aux -> data);
        }
        else{
            printf("\nThe value inside %d, %d", i, aux -> data);
        }
        i++;
        aux = aux -> next;
    }
    printf("\n\nThe display of the list has ended with showing %d different nodes", (i-1));
}
void owFirstModule(){
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        printf("\n\nThe list is empty, writing inside the first node position\n\nPlease print the value you want write inside the first node: ");
        scanf("%d", &(head->data));
        head->next = NULL;
        head->before = NULL;
    }
    else{
        printf("\n\nPlease write the value you want write inside the first node: ");
        scanf("%d", &(head->data));
    }
}
void owModule(int pos){
    int i = 0;
    int tempPos = pos;
    Node *aux = head;
    Node *beforeAux = NULL; 
    Node *creatorAux = NULL;
    while(aux!=NULL && (i!=(tempPos-1))){
        /*printf("\n\nSearching for the requested node...");*/
        i++;
        creatorAux = aux;//THIS WILL HELP KEEP TRACK OF WHERE THE LAST VALID NODE EXIST
        aux = aux -> next;
    }//FINDING THE REQUIRED NODE
    if(i==(tempPos-1) && aux!=NULL){
        printf("\n\nThe node has been found!\n\nPlease write the value you want to insert inside the node at position %d: ", tempPos);
        scanf("%d", &(aux->data));
    }
    else{
        if(head == NULL){
            printf("\n\nThe list is empty, there does not exist a node at position %d yet", pos);
        }
        printf("\tSORRY\n\nWe'll create a new node at position %d, just a sec!", tempPos);
        while(i<tempPos){
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode -> data = 0; //MAKING THE DATA INSIDE THE NEW NODE 0
            newNode -> next = NULL; //CREATING THE NEXT FOLLOWING NODE
            if(creatorAux!=NULL){
                creatorAux->next = newNode;
                newNode->before = creatorAux;
            }
            else{
                head = newNode;
                head->before = NULL;
            }
            creatorAux = newNode;
            i++;
        }
        printf("\n\nThe node has been created\n\nPlease write the value you want to insert inside the node at position %d: ", tempPos);
        scanf("%d", &(creatorAux->data));
    }//CREATING THE NODE AT POSITION N
}
void elimNode(){
    int answ = 0;
    int sel = 0;
    int tempSel = 0;
    Node *memClear = NULL;
    Node *aux = head;

    printf("\n\nYOU WILL ELIMINATE A NODE NOW\n\nAre you sure you want to eliminate it?\n\ntype '1' for Yes or type '0' for NO\tYour answer: ");
    scanf("%d", &answ);
    if(answ==1){
        printf("\n\nPlease write the position of the node you would like to eliminate:  ");
        scanf("%d", &tempSel);
        sel = tempSel-1;
        /*printf("\n\nVAL OF SEL %d", sel);*/
        if(head ==NULL || sel<0){
            printf("\n\nThe list is empty, there is nothing to erase or the selection was off limits < 0");
            return;
        }
        if(sel == 0){
            memClear = head;
            head = head->next;
            free(memClear);
            return;
        }
        else{
            int i = 0;
            while(aux!=NULL && i<(sel-1)){
                aux = aux -> next;
                i++;
            }//FINDING THE REQUESTED NODE
            if(aux == NULL || aux->next == NULL){
                printf("\n\nAfter checking, the position entered '%d' does not seem to exist, try again\n", sel);
                return;
            }
            memClear = aux -> next;
            aux -> next = memClear->next;
            free(memClear);
        }
    }
    else{
        return;
    }
}
void showPrevVal(){
    if(head == NULL){
        printf("\n\nThe list is empty!\tYou will have to enqueue values first.");
    }
    else{
        Node *aux = head;
        int i = 1;
        int pos = 0;
        showModules();//TEST
        while(aux!=NULL){
            printf("\nNODE %d", i);
            aux = aux->next;
            i++;
        }
        i=1;
        aux = head;
        while(aux->next!=NULL){
                aux = aux->next; 
                i++; 
            }//Finding the last node in order to join it with head->before
            head->before = aux;
            aux->next = head;
        printf("\n\nPlease write the position of the node you would like to know the previous value of:  ");
        scanf("%d", &pos);
        if(pos == 1){//THIS WILL MEAN THAT THE VALUE WE WANT TO KNOW IS THE LAST FROM HEAD
            printf("\n\nWe have made a cycle out of all of the nodes in the list. \n\nThe present case will show the value behind the first node (being the last node of the list).");
            printf("\n\nThe value before the first node is %d", head->before->data);
        }
        else{
            printf("\n\nWe have made a cycle out of all of the nodes in the list. \n\nThe present case will show the value behind the node at %d ", pos);
            Node *aux2 = head;
            while(aux2->next != NULL && i<pos){
                aux2 = aux2->next;
                i++;
            }//Searching for the required node
            Node *tempAux = aux2->before;
            printf("\n\nThe previous value to the node at position %d, is %d", pos, tempAux->before->data);
        }
        head->before = NULL;
        aux->next = NULL;
        //UNLINKING THE CIRCULAR LIST
    }
}
