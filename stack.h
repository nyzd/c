#ifndef STACK_H_

#define STACK_H_

typedef struct stack_s {
    int max;
    int top;
    int* inner;
} Stack;

Stack new_stack(int);
int push(Stack*, int);
int pop(Stack*);

#endif // !STRING_H_
