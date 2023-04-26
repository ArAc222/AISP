#include <stdio.h>
#include <stdlib.h>

// Rekurzivno računanje povrh(n,m)
int povrh(int n, int m) {
    if (m == 0 || n == m) {
        return 1;
    } else {
        return povrh(n - 1, m - 1) + povrh(n - 1, m);
    }
}

// Implementacija stoga pomoću povezanog popisa
typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void push(Stack* stack, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        Node* temp = stack->top;
        int value = temp->value;
        stack->top = temp->next;
        free(temp);
        return value;
    }
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack->top->value;
    }
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Računanje povrh(n,m) pomoću stoga
int povrhStack(int n, int m) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;

    push(stack, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 1; j--) {
            if (j > m && i - j > m - 1) {
                int a = pop(stack);
                int b = pop(stack);
                push(stack, a + b);
            } else if (j <= m) {
                push(stack, 1);
            }
        }
        push(stack, 1);
    }

    int result = peek(stack);
    free(stack);

    return result;
}

int main() {
    int n = 10;
    int m = n / 2;

    // Računanje povrh(n,m) rekurzivno
    int result_recursive = povrh(n, m);
    printf("Recursive result: %d\n", result_recursive);

    // Računanje povrh(n,m) pomoću stoga
    int result_stack = povrhStack(n, m);
    printf("Stack result: %d\n", result_stack);

    return 0;
}
