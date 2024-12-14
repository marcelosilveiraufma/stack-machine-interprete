#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(Stack *stack) {
    stack->top = -1;
}

void push_stack(Stack *stack, int value) {
    if (stack->top >= STACK_MAX - 1) {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

int pop_stack(Stack *stack) {
    if (stack->top < 0) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}
