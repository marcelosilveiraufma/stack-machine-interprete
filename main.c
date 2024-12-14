#include <stdio.h>
#include "stack.h"
#include "interpret.h"

int main() {
    init_stack(&stack);  // Inicializa a pilha
    repl();
    return 0;
}
