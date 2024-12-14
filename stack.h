#ifndef stack_h
#define stack_h

#define STACK_MAX 100

typedef struct {
    int data[STACK_MAX];
    int top;
} Stack;

void init_stack(Stack *stack);
void push_stack(Stack *stack, int value);
int pop_stack(Stack *stack);
int is_empty(Stack *stack);

#endif
