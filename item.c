#include <stdio.h>

void displayItems() {
    printf("Grocery Items available:\n");
    printf("Category: Grains\n");
    printf("1. Rice (5kg)          - Rs. 200    (Quantity: 50)\n");
    printf("2. Wheat Flour (10kg)  - Rs. 300    (Quantity: 30)\n");
    printf("\n");
    printf("Category: Cooking Essentials\n");
    printf("3. Cooking Oil (1L)    - Rs. 150    (Quantity: 40)\n");
    printf("4. Salt (1kg)          - Rs. 20     (Quantity: 60)\n");
    printf("5. Sugar (1kg)         - Rs. 40     (Quantity: 45)\n");
    printf("\n");
    printf("Category: Fruits\n");
    printf("6. Apples (500g)       - Rs. 80     (Quantity: 70)\n");
    printf("7. Bananas (500g)      - Rs. 40     (Quantity: 100)\n");
    printf("8. Grapes (500g)       - Rs. 50     (Quantity: 80)\n");
    printf("9. Oranges (500g)      - Rs. 60     (Quantity: 90)\n");
}

float getItemPrice(int itemId) {
    float price = 0.0;
    switch (itemId) {
        case 1:
            price = 200.0;
            break;
        case 2:
            price = 300.0;
            break;
        case 3:
            price = 150.0;
            break;
        case 4:
            price = 20.0;
            break;
        case 5:
            price = 40.0;
            break;
        case 6:
            price = 80.0;
            break;
        case 7:
            price = 40.0;
            break;
        case 8:
            price = 50.0;
            break;
        case 9:
            price = 60.0;
            break;
        default:
            printf("Invalid item ID.\n");
            break;
    }
    return price;
}
