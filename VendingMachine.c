#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    printf("0 - Cancel Purchase\n");
    printf("Q - Quit\n");
}

// Function to handle product selection by the consumer
void selectProduct(char choice) {
    // ... (as in the previous code)
}

// Function to replenish items with random quantities
void replenishItems() {
    srand(time(NULL));
    quantityA = rand() % 20 + 1;
    quantityB = rand() % 20 + 1;
    quantityC = rand() % 20 + 1;
    printf("Items replenished with random quantities.\n");
}

// Function to change item prices
void changeItemPrices() {
    printf("Enter the new price for product A: $");
    scanf("%lf", &priceA);
    printf("Enter the new price for product B: $");
    scanf("%lf", &priceB);
    printf("Enter the new price for product C: $");
    scanf("%lf", &priceC);
    printf("Item prices updated.\n");
}

// Function to display total sales and reset if required
void displayTotalSale() {
    printf("Total Sales: $%.2lf\n", total_amount);
    char resetChoice;
    printf("Reset total sales to zero? (Y/N): ");
    scanf(" %c", &resetChoice);
    if (resetChoice == 'Y' || resetChoice == 'y') {
        printf("Total sales reset to zero. Remember to collect the money from the machine.\n");
        total_amount = 0.0;
    }
}

// Function to display item availability
void displayItemAvailability() {
    printf("Item Availability:\n");
    printf("A - Quantity: %d\n", quantityA);
    printf("B - Quantity: %d\n", quantityB);
    printf("C - Quantity: %d\n", quantityC);
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
        } else if (choice == '0') {
            int adminPassword;
            printf("Enter the admin password: ");
            scanf("%d", &adminPassword);
            
            if (adminPassword != password) {
                printf("Incorrect password. Exiting Admin mode.\n");
                continue;
            }
            
            int adminChoice;
            while (1) {
                printf("\nAdmin Menu:\n");
                printf("1: Replenish Items\n");
                printf("2: Change Item Prices\n");
                printf("3: Display Total Sale\n");
                printf("4: Display Item Availability\n");
                printf("0: Exit Admin Mode\n");
                printf("Enter your choice: ");
                scanf("%d", &adminChoice);
                
                switch (adminChoice) {
                    case 1:
                        replenishItems();
                        break;
                    case 2:
                        changeItemPrices();
                        break;
                    case 3:
                        displayTotalSale();
                        break;
                    case 4:
                        displayItemAvailability();
                        break;
                    case 0:
                        printf("Exiting Admin mode.\n");
                        break;
                    default:
                        printf("Invalid choice in Admin mode.\n");
                }
                
                if (adminChoice == 0) {
                    break;
                }
            }
        } else {
            selectProduct(choice);
        }
    }
    
    return 0;
}
