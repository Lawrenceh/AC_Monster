/* The key here is to construct a stack with two elements instead of just one standing for the data
 * - DATA
 * - MIN of the previous ones
 */

struct MinStackElement {
    int data;
    int min;
}

struct MinStack {
    MinStackElement *data;
    int size;
    int top;
}

MinStack MinStackInit(int maxSize) {
    MinStack stack;
    stack.size = maxSize;
    stack.data = (MinStackElement *) malloc(sizeof(MinStackElement) *maxSize);
    stack.top = 0;
    return stack;
}

void MinStackFree(MinStack &stack) {
    free(stack.data);
}

MinStack MinStackPush(MinStack stack, int d) {
    if (stack.top == stack.size) error("out of stack space");
    MinStackElement *p = stack.data[stack.top];
    p->data = d;
    p->min = (stack.top == 0 ? d : stack.data[top - 1].min);
    if (p->min > d) p->min = d;
    stack.top ++;
    return stack;
}
