#include <stdio.h>

float getItemPrice(int itemId);

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

float generateBill(Item *items, int *itemIds, int *quantities, int itemCount) {
    float total = 0.0;
    printf("Generating Bill...\n");
    printf("Item\t\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < itemCount; ++i) {
        float price = getItemPrice(itemIds[i]);
        int availableQuantity = items[itemIds[i] - 1].quantity;
        if (quantities[i] > availableQuantity) {
            printf("Error: Not enough stock for Item %d\n", itemIds[i]);
            continue;
        }
        printf("Item %d\t\t%d\t\tRs. %.2f\n", itemIds[i], quantities[i], price);
        total += price * quantities[i];
        items[itemIds[i] - 1].quantity -= quantities[i];
    }
    printf("--------------------------------------------\n");
    printf("Total\t\t\t\tRs. %.2f\n", total);

    if (total >= 1000) {
        total -= 50;
        printf("Discount Applied: Rs. 50\n");
        printf("New Total\t\t\tRs. %.2f\n", total);
    }

    return total;
}
