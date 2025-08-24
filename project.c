#include <stdio.h>
#include <stdlib.h>

int main() {
    int password, enteredPassword;
    float balance = 1000.0; 
    int choice;
    float amount;

    password = 1234; 
    printf("==== Welcome to Simple ATM Simulator ====\n");

    
    printf("Enter your ATM password: ");
    scanf("%d", &enteredPassword);

    if (enteredPassword != password) {
        printf("Incorrect password. Access denied!\n");
        return 0;
    }

    do {
        printf("\n========= ATM Menu =========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Your current balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Successfully deposited %.2f\n", amount);
                } else {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("Enter withdraw amount: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Successfully withdrew %.2f\n", amount);
                } else {
                    printf("Insufficient balance or invalid amount!\n");
                }
                break;

            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}
