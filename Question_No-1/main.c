#include <stdio.h>
#include <stdlib.h>

//Represents arithmetic operations and their corresponding operands
typedef struct Node
{
    TypeTag type;
    void* value;
} Node;

//Defines different types of arithmetic operations
typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    FIBO
} TypeTag;

//Allocate memory for a node and set its type
Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->value = NULL;
    return node;
}

void calc(Node* node);

//Evaluates the fibonacci sequence
int fibonacci(int n) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}

//Evaluates arithmetic operations
void calc(Node* node) {
    if (node == NULL)
        return;

    switch (node->type) {
        case ADD: {
            int* values = (int*)node->value;
            int result = values[0] + values[1];
            printf("add: %d\n", result);
            break;
        }
        case MUL: {
            int* values = (int*)node->value;
            int result = values[0] * values[1];
            printf("mul: %d\n", result);
            break;
        }
        case SUB: {
            int* values = (int*)node->value;
            int result = values[0] - values[1];
            printf("sub: %d\n", result);
            break;
        }
        case FIBO: {
            int* value = (int*)node->value;
            int result = fibonacci(*value);
            printf("fibo: %d\n", result);
            break;
        }
    }
}

int main() {
    Node* add = (*makeFunc(ADD));
    int addValues[2] = {10, 6};
    add->value = addValues;

    Node* mul = (*makeFunc(MUL));
    int mulValues[2] = {5, 4};
    mul->value = mulValues;

    Node* sub = (*makeFunc(SUB));
    sub->value = malloc(sizeof(int*));
    *((int*)sub->value) = 0;

    Node* fibo = (*makeFunc(FIBO));
    fibo->value = malloc(sizeof(int));
    *((int*)fibo->value) = 0;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub->value);
    free(sub);
    free(fibo->value);
    free(fibo);

    return 0;
}
