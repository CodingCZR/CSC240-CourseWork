#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void push(Node **stack, char op, int number);
int pop(Node **stack, char *op, int *number);
void calculatorOperations(char op, int number, int *result);
void undoCalculatorOperation(Node **undoStack, Node **redoStack, int *result);
void redoCalculatorOperation(Node **undoStack, Node **redoStack, int *result);

// Node structure for the stack
typedef struct node {
    char op;            // Operator (+, -, *)
    int number;         // Operand (number)
    struct node *next;  // Pointer to next node
} Node;

// Main function
int main() {
    Node *undoStack = NULL;  // Undo stack
    Node *redoStack = NULL;  // Redo stack
    int result;              // Calculator result
    char op;
    int number;

    // Get starting value
    printf("C Calculator\n+----------------+\n");
    printf("Enter starting value: ");
    scanf("%d", &result);

    // Calculator loop
    while (1) {
        printf("Enter operation (+, -, *, u-Undo, r-Redo, q-Quit): ");
        scanf(" %c", &op);  // Read operation

        if (op == 'q') break;  // Quit

        if (op == 'u') {
            undoCalculatorOperation(&undoStack, &redoStack, &result);
        } else if (op == 'r') {
            redoCalculatorOperation(&undoStack, &redoStack, &result);
        } else if (op == '+' || op == '-' || op == '*') {
            printf("Enter a number: ");
            scanf("%d", &number);  // Read number
            push(&undoStack, op, number);  // Save to undo stack
            calculatorOperations(op, number, &result);  // Perform operation

            // Clear redo stack after new operation
            while (pop(&redoStack, &op, &number));
        } else {
            printf("*** Invalid operation.\n");
        }

        printf("Result = %d\n", result);  // Show result
    }

    // Free memory before exit
    while (pop(&undoStack, &op, &number));
    while (pop(&redoStack, &op, &number));

    printf("Calculator exited.\n");
    return 0;
}

// Push operation to stack
void push(Node **stack, char op, int number) {
    Node *newNode = (Node *)malloc(sizeof(Node));  // New node
    newNode->op = op;
    newNode->number = number;
    newNode->next = *stack;  // Point to current top
    *stack = newNode;  // Update top
}

// Pop operation from stack
int pop(Node **stack, char *op, int *number) {
    if (*stack == NULL) return 0;  // Empty stack

    Node *temp = *stack;  // Save current top
    *op = temp->op;
    *number = temp->number;
    *stack = temp->next;  // Update top
    free(temp);  // Free memory
    return 1;  // Success
}

// Perform arithmetic operation
void calculatorOperations(char op, int number, int *result) {
    switch (op) {
        case '+': *result += number; break;
        case '-': *result -= number; break;
        case '*': *result *= number; break;
        default: printf("*** Invalid operation.\n"); break;
    }
}

// Undo last operation
void undoCalculatorOperation(Node **undoStack, Node **redoStack, int *result) {
    char op;
    int number;
    if (pop(undoStack, &op, &number)) {
        switch (op) {
            case '+': *result -= number; break;
            case '-': *result += number; break;
            case '*': *result /= number; break;
        }
        push(redoStack, op, number);  // Save to redo stack
    } else {
        printf("*** No operation to undo.\n");
    }
}

// Redo last undone operation
void redoCalculatorOperation(Node **undoStack, Node **redoStack, int *result) {
    char op;
    int number;
    if (pop(redoStack, &op, &number)) {
        calculatorOperations(op, number, result);
        push(undoStack, op, number);  // Save to undo stack
    } else {
        printf("*** No operation to redo.\n");
    }
}
