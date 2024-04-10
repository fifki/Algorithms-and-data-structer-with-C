

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell {
    int val;
    struct Cell *next;
} Cell;

typedef struct {
    Cell *top;
} Stack;

Stack *InitStack();

void Push(Stack *stack, int value);

int Pop(Stack *stack, int *val);

void DestroyStack(Stack *stack);


 void PrintStack(Stack *stack) {
    printf("Stack: ");
    Cell *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    char input[100];
    int val;
    Stack *stack = InitStack();

    fscanf(stdin, "%99s", input);
    while (strcmp(input, "bye") != 0) {
        if (strcmp(input, "push") == 0) {
            fscanf(stdin, "%99s", input);
            val = strtol(input, NULL, 10);
            Push(stack, val);
        } else if (strcmp(input, "pop") == 0) {
            if (Pop(stack, &val)) {
                printf("%d\n", val);
            }
        }
        PrintStack(stack);
        fscanf(stdin, "%99s", input);
    }
    DestroyStack(stack);
    return 0;
}

Stack *InitStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void Push(Stack *stack, int value) {
    Cell *c = (Cell *)malloc(sizeof(Cell));
    c->val = value;
    c->next = stack->top;
    stack->top = c;
}

int Pop(Stack *stack, int *res) {
    if (stack->top == NULL) {
        return 0; // Stack is empty
    }
    Cell *toFree = stack->top;
    *res = stack->top->val;
    stack->top = stack->top->next;
    free(toFree);
    return 1;
}

void DestroyStack(Stack *stack) {
    while (stack->top != NULL) {
        Cell *toFree = stack->top;
        stack->top = stack->top->next;
        free(toFree);
    }
    free(stack);
} 


