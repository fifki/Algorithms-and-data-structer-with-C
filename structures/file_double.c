#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 101

typedef struct Cell {
    int val;
    struct Cell* next;
} Cell;

typedef struct {
    Cell* first;
    Cell* last;
} Queue;

Queue* Init(int size);
void InsererDebut(Queue* queue, int value);
void InsererFin(Queue* queue, int value);
int SupprimerDebut(Queue* queue);
int SupprimerFin(Queue* queue);
void EnQueue(Queue* queue, int value);
int DeQueue(Queue* queue, int* val);
void Destroy(Queue* queue);

int main(void) {
    char lecture[100];
    int val;
    Queue* queue;
    queue = Init(10);

    fscanf(stdin, "%99s", lecture);
    while (strcmp(lecture, "bye") != 0) {
        if (strcmp(lecture, "queue") == 0) {
            fscanf(stdin, "%99s", lecture);
            val = strtol(lecture, NULL, 10);
            EnQueue(queue, val);
        } else if (strcmp(lecture, "dequeue") == 0) {
            if (DeQueue(queue, &val)) {
                printf("%d\r\n", val);
            }
        } else if (strcmp(lecture, "insererdebut") == 0) {
            fscanf(stdin, "%99s", lecture);
            val = strtol(lecture, NULL, 10);
            InsererDebut(queue, val);
        } else if (strcmp(lecture, "insererfin") == 0) {
            fscanf(stdin, "%99s", lecture);
            val = strtol(lecture, NULL, 10);
            InsererFin(queue, val);
        } else if (strcmp(lecture, "supprimerdebut") == 0) {
            if (SupprimerDebut(queue)) {
                printf("Supprimé premier élément.\r\n");
            } else {
                printf("La file est vide.\r\n");
            }
        } else if (strcmp(lecture, "supprimerfin") == 0) {
            if (SupprimerFin(queue)) {
                printf("Supprimé dernier élément.\r\n");
            } else {
                printf("La file est vide.\r\n");
            }
        }
        fscanf(stdin, "%99s", lecture);
    }
    Destroy(queue);
    return 0;
}

Queue* Init(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

void EnQueue(Queue* queue, int value) {
    Cell* c = (Cell*)malloc(sizeof(Cell));
    c->val = value;
    c->next = NULL;
    if (!queue->last) {
        queue->first = c;
    } else {
        queue->last->next = c;
    }
    queue->last = c;
}

int DeQueue(Queue* queue, int* res) {
    if (!queue->first) {
        return 0;
    }
    Cell* toFree = queue->first;
    *res = queue->first->val;
    queue->first = queue->first->next;
    if (!queue->first) {
        queue->last = NULL;
    }
    free(toFree);
    return 1;
}

void Destroy(Queue* queue) {
    free(queue);
}

void InsererDebut(Queue* queue, int value) {
    Cell* newCell = (Cell*)malloc(sizeof(Cell));
    newCell->val = value;
    newCell->next = queue->first;
    queue->first = newCell;
    if (!queue->last) {
        queue->last = newCell;
    }
}

void InsererFin(Queue* queue, int value) {
    EnQueue(queue, value);
}

int SupprimerDebut(Queue* queue) {
    if (!queue->first) {
        return 0; // File vide
    }
    Cell* toFree = queue->first;
    queue->first = queue->first->next;
    free(toFree);
    if (!queue->first) {
        queue->last = NULL;
    }
    return 1;
}

int SupprimerFin(Queue* queue) {
    if (!queue->first) {
        return 0; // File vide
    }
    if (queue->first == queue->last) {
        free(queue->first);
        queue->first = NULL;
        queue->last = NULL;
        return 1;
    }
    Cell* current = queue->first;
    while (current->next != queue->last) {
        current = current->next;
    }
    free(queue->last);
    queue->last = current;
    current->next = NULL;
    return 1;
}
