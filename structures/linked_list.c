#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    size_t size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void insertNode(LinkedList* list, size_t index, int value) {
    if (index > list->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* current = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;
}

int retrieveNode(LinkedList* list, size_t index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

void deleteNode(LinkedList* list, size_t index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    Node* temp;
    if (index == 0) {
        temp = list->head;
        list->head = list->head->next;
    } else {
        Node* current = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }

    free(temp);
    list->size--;
}

size_t getSize(LinkedList* list) {
    return list->size;
}

void printLinkedList(LinkedList* list) {
    Node* current = list->head;
    printf("Linked List: [ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

void destroyLinkedList(LinkedList* list) {
    Node* current = list->head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main(void) {
    char command[100];
    int value, index;
    LinkedList* list = createLinkedList();

    fscanf(stdin, "%99s", command);
    while (strcmp(command, "bye") != 0) {
        if (strcmp(command, "insert") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            fscanf(stdin, "%99s", command);
            value = strtol(command, NULL, 10);
            insertNode(list, index, value);
        }
        else if (strcmp(command, "delete") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            deleteNode(list, index);
        }
        else if (strcmp(command, "retrieve") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            printf("Element at position %d: %d\n", index, retrieveNode(list, index));
        }
        else if (strcmp(command, "size") == 0) {
            printf("Linked List size: %zu\n", getSize(list));
        }
        else if (strcmp(command, "print") == 0) {
            printLinkedList(list);
        }
        else if (strcmp(command, "destroy") == 0) {
            destroyLinkedList(list);
            printf("Linked List destroyed.\n");
        }
        fscanf(stdin, "%99s", command);
    }

    destroyLinkedList(list);
    return 0;
}
/*
insert 0 10
insert 1 20
print
delete 1
print
size
destroy
bye

*/