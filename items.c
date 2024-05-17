#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char category[50];
    int quantity;
    float price;
} Item;

Item items[] = {
    {1, "Rice", "Grains", 20, 200.0},
    {2, "Wheat Flour", "Grains", 15, 300.0},
    {3, "Cooking Oil", "Cooking Essentials", 30, 150.0},
    {4, "Salt", "Cooking Essentials", 50, 20.0},
    {5, "Sugar", "Cooking Essentials", 40, 40.0},
    {6, "Apples", "Fruits", 25, 80.0},
    {7, "Bananas", "Fruits", 35, 40.0},
    {8, "Grapes", "Fruits", 30, 50.0},
    {9, "Oranges", "Fruits", 20, 60.0}
};

void displayItems() {
    printf("Grocery Items available:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("ID     Name\t\t       Category\t            Quantity\t\t  Price\n");
    printf("-----------------------------------------------------------------------------------\n");
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        printf("%-7d%-24s%-24s%-16dRs. %.2f\n", items[i].id, items[i].name, items[i].category, items[i].quantity, items[i].price);
    }
}

void searchItem() {
    char searchName[50];
    printf("Enter the name of the item to search: ");
    scanf("%s", searchName);

    printf("-----------------------------------------------------------------------------------\n");
    printf("ID     Name\t\t       Category\t            Quantity\t\t  Price\n");
    printf("-----------------------------------------------------------------------------------\n");
    int found = 0;
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        if (strcasecmp(items[i].name, searchName) == 0) {
            printf("%-7d%-24s%-24s%-16dRs. %.2f\n", items[i].id, items[i].name, items[i].category, items[i].quantity, items[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Item not found.\n");
    }
    printf("-----------------------------------------------------------------------------------\n");
}

float getItemPrice(int itemId) {
    for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
        if (items[i].id == itemId) {
            return items[i].price;
        }
    }
    printf("Invalid item ID.\n");
    return 0.0;
}
