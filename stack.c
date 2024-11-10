#include "./stack.h"
#include <stdlib.h>

Stack new_stack(int max) {
    int* inner = (int*)malloc(sizeof(int)* max);
    Stack stack = {
        max,
        0,
        inner,
    };

    return stack;
}

int push(Stack* stack, int val) {
    if (stack->top >= stack->max) {
        return 1;
    }

    stack->inner[stack->top] = val;
    stack->top += 1;

    return 0;
}

int pop(Stack *stack) {
    if (stack->top <= 0) {
        return 1;
    }

    int tmp = stack->inner[stack->top - 1];

    stack->top -= 1;

    return tmp;
}
