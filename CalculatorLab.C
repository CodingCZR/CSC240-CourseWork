#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
typedef struct node {
    char op;    // Store the operator (like +, -, *)
    int number; // Store the operand (number)
    struct node *next; // Pointer to the next node
} Node;

// Function prototypes
void push(Node **stack, char op, int number);
int pop(Node **stack, char *op, int *number);
void calculatorOperations(char op, int number, int *result);
void undoCalculatorOperation(Node **undoStack, Node **redoStack, int *result);
void redoCalculatorOperation(Node **undoStack, Node **redoStack, int *result);

// Main function
int main() {
    Node *undoStack = NULL; // Stack to store undo operations
    Node *redoStack = NULL; // Stack to store redo operations
    int result;             // Current result of the calculator
    char op;
    int number;

    printf("C Calculator\n+----------------+\n");
    printf("Enter starting value: ");
    scanf("%d", &result);

    // Main calculator loop
    while (1) {
        printf("Enter next operation (+, -, *, u-Undo, r-Redo, q-Quit): ");
        scanf(" %c", &op); // Read operation input

        if (op == 'q') {
            break; // Quit the calculator
        } else if (op == 'u') {
            undoCalculatorOperation(&undoStack, &redoStack, &result);
        } else if (op == 'r') {
            redoCalculatorOperation(&undoStack, &redoStack, &result);
        } else if (op == '+' || op == '-' || op == '*') {
            printf("Enter a number: ");
            scanf("%d", &number); // Read the number
            push(&undoStack, op, number); // Save the operation to the undo stack
            calculatorOperations(op, number, &result); // Perform the operation

            // Clear the redo stack after a new operation
            while (pop(&redoStack, &op, &number));
        } else {
            printf("*** Not a valid operation.\n");
        }

        printf("Result = %d\n", result); // Display the current result
    }

    // Free memory used by stacks before exiting
    while (pop(&undoStack, &op, &number));
    while (pop(&redoStack, &op, &number));

    printf("Calculator exited.\n");
    return 0;
}

// Function to push a new operation onto the stack
void push(Node **stack, char op, int number) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->op = op;
    newNode->number = number;
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop an item from the stack
int pop(Node **stack, char *op, int *number) {
    if (*stack == NULL) {
        return 0; // Stack is empty
    }
    Node *temp = *stack;
    *op = temp->op;
    *number = temp->number;
    *stack = temp->next;
    free(temp); // Free memory
    return 1;
}

// Function to perform arithmetic operations
void calculatorOperations(char op, int number, int *result) {
    switch (op) {
    case '+':
        *result += number;
        break;
    case '-':
        *result -= number;
        break;
    case '*':
        *result *= number;
        break;
    default:
        printf("*** Invalid operation.\n");
        break;
    }
}

// Function to undo the last operation
void undoCalculatorOperation(Node **undoStack, Node **redoStack, int *result) {
    char op;
    int number;
    if (pop(undoStack, &op, &number)) {
        switch (op) {
        case '+':
            *result -= number;
            break;
        case '-':
            *result += number;
            break;
        case '*':
            *result /= number;
            break;
        }
        push(redoStack, op, number); // Save the undone operation
    } else {
        printf("*** No operation to undo.\n");
    }
}

// Function to redo the last undone operation
void redoCalculatorOperation(Node **undoStack, Node **redoStack, int *result) {
    char op;
    int number;
    if (pop(redoStack, &op, &number)) {
        calculatorOperations(op, number, result);
        push(undoStack, op, number); // Save the redone operation
    } else {
        printf("*** No operation to redo.\n");
    }
}
