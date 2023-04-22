#include "stack.h"

double stack[len + 1] = {0};
double pop_value;

bool push(double value) {
    if (stack[0] == 100) {
        puts("error: stack is full");
        return false;
    }
    stack[(int) (++stack[0])] = value;
    return true;
}

bool pop() {
    if (!stack[0]) {
        puts("error: stack is void");
        return false;
    }
    pop_value = stack[(int) (stack[0]--)];
    return true;
}