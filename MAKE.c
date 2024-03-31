#include <stdio.h>
#include "login.c"
#include "item.c"
#include "bill.c"

#define MAX_ITEMS 10

int main() {
    if (loginUser()) {
        displayItems();
        int itemIds[MAX_ITEMS];
        int quantities[MAX_ITEMS];
        int itemCount = 0;
        char choice;
        do {
            printf("Enter item ID: ");
            scanf("%d", &itemIds[itemCount]);
            printf("Enter quantity: ");
            scanf("%d", &quantities[itemCount]);
            itemCount++;
            printf("Do you want to add more items? (y/n): ");
            scanf(" %c", &choice);
        }
        while (choice == 'y' && itemCount < MAX_ITEMS);

        float totalBill = generateBill(itemIds, quantities, itemCount);
        printf("Thank you for shopping!\n");
    }
    else
    {
        printf("Login failed. Exiting...\n");
    }
    return 0;
}
