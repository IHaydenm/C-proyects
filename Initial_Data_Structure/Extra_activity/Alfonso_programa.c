#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
} Nodo;

Nodo *front = NULL;
Nodo *rear = NULL;
int colaRango = 0;

// MOSTRAR ---------------------------------------
void MostrarCola() {
    if (front == NULL) {
        printf("\nCola vacía.\n");
        return;
    }
    
    Nodo *aux = front;
    printf("\nCola: ");
    while (aux != NULL) {
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    }
    printf("\n");
}

// ENCOLAR (enqueue) -------------------------------------------
void enqueue(int valor) {
    if (colaRango == MAX) {
        printf("La cola está llena\n");
        return;
    }
    
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = rear;

    if (rear == NULL) { // primera inserción
        front = rear = nuevo;
    } else {
        rear->siguiente = nuevo;
        rear = nuevo;
    }
    
    colaRango++;
    printf("Elemento %d añadido a cola\n", valor);
}

// DESENCOLAR (dequeue FIFO) -------------------------------------
void dequeue() {
    if (front == NULL) {
        printf("\nNo hay nada en la cola\n");
        return;
    }
    
    Nodo *temp = front;
    int valor = temp->dato;
    
    front = front->siguiente;
    if (front != NULL) {
        front->anterior = NULL;
    } else {
        rear = NULL; // la cola quedó vacía
    }

    free(temp);
    colaRango--;
    printf("\nElemento %d desencolado.\n", valor);
}

// ELIMINAR un nodo con un valor específico -------------------------
void eliminarNodo(int valor) {
    if (front == NULL) {
        printf("\nLa cola está vacía\n");
        return;
    }

    Nodo *aux = front;
    while (aux != NULL && aux->dato != valor) {
        aux = aux->siguiente;
    }

    if (aux == NULL) {
        printf("\nEl valor %d no se encontró en la cola\n", valor);
        return;
    }

    if (aux->anterior != NULL) {
        aux->anterior->siguiente = aux->siguiente;
    } else {
        front = aux->siguiente; // era el primero
    }

    if (aux->siguiente != NULL) {
        aux->siguiente->anterior = aux->anterior;
    } else {
        rear = aux->anterior; // era el último
    }

    printf("\nElemento %d eliminado de la cola.\n", aux->dato);
    free(aux);
    colaRango--;
}

// MAIN -----------------------------------------------------------
int main() {
    int inputUsuarioElegir, valor;

    // Insertar 5 elementos iniciales
    for (int i = 1; i <= 5; i++) {
        enqueue(i);
    }
    MostrarCola();

    do {
        printf("\n1. Enqueue (insertar)\n");
        printf("2. Dequeue (extraer primero)\n");
        printf("3. Eliminar un valor específico\n");
        printf("4. Salir\n");
        printf("\nElige una opción: ");
        
        scanf("%d", &inputUsuarioElegir);

        switch (inputUsuarioElegir) {
            case 1:
                printf("Ingrese el valor a encolar:\n");
                scanf("%d", &valor);
                enqueue(valor);
                MostrarCola();
                break;
                
            case 2:
                dequeue();
                MostrarCola();
                break;
                
            case 3:
                printf("Inserta valor a eliminar:\n");
                scanf("%d", &valor);
                eliminarNodo(valor);
                MostrarCola();
                break;
                
            case 4:
                printf("BYE BYE\n");
                break;
                
            default:
                printf("ERROR\n");
        }
    } while (inputUsuarioElegir != 4);

    return 0;
}
