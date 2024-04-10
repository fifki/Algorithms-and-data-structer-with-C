#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector* createVector() {
    Vector *vec = (Vector*)malloc(sizeof(Vector));
    if (vec == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    vec->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (vec->data == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
    return vec;
}

void resize(Vector *vec) {
    vec->capacity *= 2;
    vec->data = (int*)realloc(vec->data, vec->capacity * sizeof(int));
    if (vec->data == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

int ElementPosition(Vector *vec, size_t i) {
    if (i < 0 || i >= vec->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return vec->data[i];
}

void ReplacePosition(Vector *vec, size_t i, int value) {
    if (i < 0 || i >= vec->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    vec->data[i] = value;
}

void InsertPosition(Vector *vec, size_t i, int value) {
    if (i < 0 || i > vec->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    if (vec->size == vec->capacity) {
        resize(vec);
    }
    for (size_t j = vec->size; j > i; --j) {
        vec->data[j] = vec->data[j - 1];
    }
    vec->data[i] = value;
    vec->size++;
}

void DeletePosition(Vector *vec, size_t i) {
    if (i < 0 || i >= vec->size) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    for (size_t j = i; j < vec->size - 1; ++j) {
        vec->data[j] = vec->data[j + 1];
    }
    vec->size--;
}

size_t Size(Vector *vec) {
    return vec->size;
}

void PrintVector(Vector *vec) {
    printf("Vector: [ ");
    for (size_t i = 0; i < vec->size; ++i) {
        printf("%d ", vec->data[i]);
    }
    printf("]\n");
}

void destroyVector(Vector *vec) {
    free(vec->data);
    free(vec);
}

int main(void) {
    char command[100];
    int value, index;
    Vector *vector = createVector();

    fscanf(stdin, "%99s", command);
    while (strcmp(command, "bye") != 0) {
        if (strcmp(command, "element") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            printf("Element at position %d: %d\n", index, ElementPosition(vector, index));
        }
        else if (strcmp(command, "replace") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            fscanf(stdin, "%99s", command);
            value = strtol(command, NULL, 10);
            ReplacePosition(vector, index, value);
        }
        else if (strcmp(command, "insert") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            fscanf(stdin, "%99s", command);
            value = strtol(command, NULL, 10);
            InsertPosition(vector, index, value);
        }
        else if (strcmp(command, "delete") == 0) {
            fscanf(stdin, "%99s", command);
            index = strtol(command, NULL, 10);
            DeletePosition(vector, index);
        }
        else if (strcmp(command, "size") == 0) {
            printf("Vector size: %zu\n", Size(vector));
        }
        else if (strcmp(command, "print") == 0) {
            PrintVector(vector);
        }
         else if (strcmp(command, "destroy") == 0) {
            destroyVector(vector);
            printf("Vector destroyed.\n");
            
        }
        fscanf(stdin, "%99s", command);
    }
    
    destroyVector(vector);
    return 0;
}

