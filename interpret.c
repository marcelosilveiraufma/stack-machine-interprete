#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "interpret.h"

static Stack stack;

void interpret(const char *source) {
    char op[10];
    char arg[10];

    sscanf(source, "%s %s", op, arg);

    if (strcmp(op, "push") == 0) {
        int value = atoi(arg);  // Converte o argumento para inteiro
        push_stack(&stack, value);
    } else if (strcmp(op, "add") == 0) {
        int b = pop_stack(&stack);
        int a = pop_stack(&stack);
        push_stack(&stack, a + b);
    } else if (strcmp(op, "sub") == 0) {
        int b = pop_stack(&stack);
        int a = pop_stack(&stack);
        push_stack(&stack, a - b);
    } else if (strcmp(op, "mul") == 0) {
        int b = pop_stack(&stack);
        int a = pop_stack(&stack);
        push_stack(&stack, a * b);
    } else if (strcmp(op, "div") == 0) {
        int b = pop_stack(&stack);
        int a = pop_stack(&stack);
        if (b == 0) {
            printf("Erro: Divisão por zero\n");
            exit(1);
        }
        push_stack(&stack, a / b);
    } else if (strcmp(op, "print") == 0) {
        int value = pop_stack(&stack);
        printf("Resultado: %d\n", value);
    } else {
        printf("Comando não reconhecido: %s\n", op);
    }
}
