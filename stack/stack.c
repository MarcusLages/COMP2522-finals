#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

Stack* createStack(int capacity) {
    Stack* stack = (Stack *)malloc(sizeof(Stack));

    stack->capacity = capacity;
    stack->top = EMPTY_TOP;
    stack->items = (void **)calloc(capacity, sizeof(void*));

    return stack;
}

int isFull(Stack *stack) {
    return stack->top == (stack->capacity - 1);
}

int isEmpty(Stack *stack) {
    return stack->top == EMPTY_TOP;
}

void push(Stack *stack, void *item, int itemSize) {

    if(isFull(stack)) {
        stack->capacity *= 2;
        stack->items = realloc(stack->items, stack->capacity);
    }

    stack->top++;
    stack->items[stack->top] = malloc(itemSize);

    memcpy(stack->items[stack->top], item, itemSize);
}

void pop(Stack *stack, void *item, int itemSize) {
    if(stack == NULL || item == NULL) return;

    if(isEmpty(stack)) {
        perror("Stack is empty, impossible to pop.");
        return;
    }

    memcpy(item, stack->items[stack->top], itemSize);
    free(stack->items[stack->top]);
    stack->items[stack->top] = NULL;
    stack->top--;
}

void freeStack(Stack *stack) {
    while(!isEmpty(stack)) {
        int item;
        pop(stack, &item, sizeof(int));
    }

    free(stack->items);
    free(stack);
}

void printIntStack(Stack *stack) {
    while(!isEmpty(stack)) {
        int item;
        pop(stack, &item, sizeof(int));
        printf("%d ", item);
    }
}

int main() {
    Stack *stack = createStack(5);
    int i = 1;

    push(stack, &i, sizeof(int));
    i = 2;
    push(stack, &i, sizeof(int));
    i = 3;
    push(stack, &i, sizeof(int));
    i = 4;
    push(stack, &i, sizeof(int));

    printIntStack(stack);
    freeStack(stack);
    
    return 0;
}