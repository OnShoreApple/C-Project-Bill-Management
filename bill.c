#include <stdio.h>

float generateBill(int *itemIds, int *quantities, int itemCount) {
    float total = 0.0;
    printf("Generating Bill...\n");
    printf("Item\t\tQuantity\tPrice\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < itemCount; ++i) {
        float price = getItemPrice(itemIds[i]);
        printf("Item %d\t\t%d\t\tRs. %.2f\n", itemIds[i], quantities[i], price);
        total += price * quantities[i];
    }
    printf("--------------------------------------------\n");
    printf("Total\t\t\t\tRs. %.2f\n", total);
    return total;
}
