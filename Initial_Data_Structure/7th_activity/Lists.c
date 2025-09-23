#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}Node;
/*variables*/
Node* head;
bool end = true;
/*VARIABLES*/
void showList();
void showModules();
void owFirstModule();
void owModule(int pos);
void elimNode();
int main(){
    head = NULL; int ans = 0;
    do{
        printf("\n\nPress '0' to create a new node and add a new value to the list\nPress '1' to see al the values inside the already created nodes\nPress '2' to write inside the first node (WARNING THIS WILL OVERWRITE THE NODE)\nPress '3 to write inside a specific node (WARNING THIS WILL OVERWRITE THE NODE)\nPress '4' to eliminate a specific node\nYour Selection: ");
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
                    scanf("%d", &(newNode->data));  newNode->next = NULL;
                    //2. agregando el nodo a la lista
                    //2.1 si la lista está vacía, este es el primer nodo
                    if(head == NULL)
                        head = newNode;
                    else
                    {
                        //2.2 Localizamos el ultimo nodo de la lista
                        Node *aux = head;
                        while (aux->next != NULL) aux = aux->next;
                        //2.3 agregamos el nuevo nodo
                        aux->next = newNode;
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
        default:
            break;
        }
    } while(end); //do
    showList();
} //main

void showList(){
    if (head == NULL)
        printf("\n La lista esta vacia!!"); 
    else{
        printf("\n Lista: ");
        Node *aux = head; 
        while(aux != NULL){
            printf("%d ", aux->data);
            aux = aux->next;
        }
    }
    printf("\n");
}
void showModules(){
    if(head == NULL){
        printf("\n\nThe list is empty!");
    }
    Node *aux = head;
    int i = 1;
    while(aux != NULL){   
        printf("\nThe value inside %d, %d", i, aux -> data);
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
    Node *creatorAux = NULL;
    while(aux!=NULL && (i!=(tempPos-1))){
        printf("\n\nSearching for the requested node...");
        i++;
        creatorAux = aux;//THIS WILL HELP KEEP TRACK OF WHERE THE LAST VALID NODE EXIST
        aux = aux -> next;
    }//FINDING THE REQUIRED NODE
    if(i==(tempPos-1) && aux!=NULL){
        printf("\n\nThe node has been found!\nPlease write the value you want to insert inside the node at position %d", tempPos);
        scanf("%d", &(aux->data));
    }
    else{
        if(head == NULL){
            printf("\n\nThe list is empty, there does not exist a node at position: %d yet", pos);
        }
        printf("\t SORRY\n\nWe'll create a new node at position %d, just a sec!", tempPos);
        while(i<tempPos){
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode -> data = 0; //MAKING THE DATA INSIDE THE NEW NODE 0
            newNode -> next = NULL; //CREATING THE NEXT FOLLOWING NODE
            if(creatorAux!=NULL){
                creatorAux-> next = newNode;
            }
            else{
                head = newNode;
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