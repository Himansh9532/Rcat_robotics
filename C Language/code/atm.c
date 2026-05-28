// Exercise 2: ATM Program (C Language)
// Objective

// Create an ATM program that allows user to:

// Check balance
// Deposit money
// Withdraw money
// Exit
// Algorithm
// Start
// Set initial balance
// Display menu
// Take user choice
// Perform transaction
// Repeat until exit
// Stop
#include <stdio.h>

int main() {
    int choice;
    float balance = 10000, deposit, withdraw;

    while(1) {
        printf("\n------ ATM MENU ------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Current Balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &deposit);

                if(deposit > 0) {
                    balance = balance + deposit;
                    printf("Deposit Successful!\n");
                    printf("Updated Balance: %.2f\n", balance);
                } else {
                    printf("Invalid deposit amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdraw);

                if(withdraw > 0 && withdraw <= balance) {
                    balance = balance - withdraw;
                    printf("Withdraw Successful!\n");
                    printf("Updated Balance: %.2f\n", balance);
                } else if(withdraw > balance) {
                    printf("Insufficient Balance!\n");
                } else {
                    printf("Invalid withdraw amount!\n");
                }
                break;

            case 4:
                printf("Thank you for using ATM.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}