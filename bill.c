#include <stdio.h>

float getItemPrice(int itemId);

float generateBill(int *itemIds, int *quantities, int itemCount) {
    printf("Generating Bill...\n");
    printf("Item\t\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    float total = 0.0;
    for (int i = 0; i < itemCount; ++i) {
        float price = getItemPrice(itemIds[i]);
        printf("Item %d\t\t%d\t\tRs. %.2f\n", itemIds[i], quantities[i], price);
        total += price * quantities[i];
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
