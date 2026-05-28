// Exercise 1: Calculator Program (C Language)
// Objective

// Create a simple calculator program that performs basic operations like addition, subtraction, multiplication, division, and modulus.

// Algorithm
// Start
// Input two numbers
// Input operator choice
// Perform operation using switch case
// Display result
// Stop
#include <stdio.h>

int main() {
    int a, b;
    char op;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &op);

    switch(op) {
        case '+':
            printf("Result = %d\n", a + b);
            break;

        case '-':
            printf("Result = %d\n", a - b);
            break;

        case '*':
            printf("Result = %d\n", a * b);
            break;

        case '/':
            if(b != 0)
                printf("Result = %d\n", a / b);
            else
                printf("Division not possible (divide by zero)\n");
            break;

        case '%':
            if(b != 0)
                printf("Result = %d\n", a % b);
            else
                printf("Modulus not possible (divide by zero)\n");
            break;

        default:
            printf("Invalid Operator\n");
    }

    return 0;
}