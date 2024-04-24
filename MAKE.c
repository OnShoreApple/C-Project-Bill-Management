#include <stdio.h>
#include <stdlib.h>
#include "login.c"
#include "item.c"
#include "bill.c"

int main() {
    User *user = loginUser();
    if (user != NULL) {
        displayItems();

        Item *items = (Item *)malloc(9 * sizeof(Item));
        if (items == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        items[0] = (Item){1, "Rice (5kg)", 200.0, 50};
        items[1] = (Item){2, "Wheat Flour (10kg)", 300.0, 30};
        items[2] = (Item){3, "Cooking Oil (1L)", 150.0, 40};
        items[3] = (Item){4, "Salt (1kg)", 20.0, 60};
        items[4] = (Item){5, "Sugar (1kg)", 40.0, 45};
        items[5] = (Item){6, "Apples (500g)", 80.0, 70};
        items[6] = (Item){7, "Bananas (500g)", 40.0, 100};
        items[7] = (Item){8, "Grapes (500g)", 50.0, 80};
        items[8] = (Item){9, "Oranges (500g)", 60.0, 90};

        int itemIds[10];
        int quantities[10];
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
        } while (choice == 'y' && itemCount < 10);

        float totalBill = generateBill(items, itemIds, quantities, itemCount);
        printf("Thank you for shopping!\n");

        free(items);
    } else {
        printf("Login failed. Exiting...\n");
    }
    return 0;
}
