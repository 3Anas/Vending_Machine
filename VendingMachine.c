#include <stdio.h>


// Constants
const double Min = 5.0;  // Minimum quantity for the alert
const int password = 1234;  // Admin password

// Product information
double priceA = 1.50;
double priceB = 2.00;
double priceC = 2.50;
int quantityA = 10;
int quantityB = 15;
int quantityC = 20;
double total_amount = 0.0;

// Function to display the product menu
void displayMenu() {
    printf("\nProduct Menu:\n");
    printf("A - Price: $%.2lf   Quantity: %d\n", priceA, quantityA);
    printf("B - Price: $%.2lf   Quantity: %d\n", priceB, quantityB);
    printf("C - Price: $%.2lf   Quantity: %d\n", priceC, quantityC);
    printf("R - Reset Total Sales\n");
    printf("Q - Quit\n");
}

// Function to handle product selection
void selectProduct(char choice) {
    double price = 0.0;
    int* quantity = NULL;
    
    switch (choice) {
        case 'A':
            price = priceA;
            quantity = &quantityA;
            break;
        case 'B':
            price = priceB;
            quantity = &quantityB;
            break;
        case 'C':
            price = priceC;
            quantity = &quantityC;
            break;
        default:
            printf("Invalid selection!\n");
            return;
    }
    
    if (*quantity <= Min) {
        printf("Alert: Quantity of product %c is low!\n", choice);
    }
    
    printf("Enter the quantity to purchase: ");
    int quantityToBuy;
    scanf("%d", &quantityToBuy);
    
    if (quantityToBuy <= *quantity) {
        *quantity -= quantityToBuy;
        double saleAmount = price * quantityToBuy;
        total_amount += saleAmount;
        printf("You bought %d of product %c for $%.2lf\n", quantityToBuy, choice, saleAmount);
    } else {
        printf("Not enough quantity in stock.\n");
    }
}

int main() {
    char choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        if (choice == 'Q') {
            printf("Exiting vending machine simulator.\n");
            break;
        } else if (choice == 'R') {
            total_amount = 0.0;
            printf("Total sales reset to $0.00\n");
        } else {
            selectProduct(choice);
        }
    }
    
    return 0;
}
