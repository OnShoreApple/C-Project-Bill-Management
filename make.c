#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* username;
    char* password;
} User;

User* loginUser();
void createUser();

void displayItems();
float getItemPrice(int itemId);
void searchItem();

float generateBill(int *itemIds, int *quantities, int itemCount);

int main() {
    int choice;
    printf("1. Login\n");
    printf("2. Create Account\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    if (choice == 2) {
        createUser();
    }
    
    User *user = loginUser();
    if (user != NULL) {
        int action;
        do {
            printf("1. Display Items\n");
            printf("2. Search Item\n");
            printf("3. Purchase Items\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &action);
            
            switch (action) {
                case 1:
                    displayItems();
                    break;
                case 2:
                    searchItem();
                    break;
                case 3: {
                    int itemIds[10];
                    int quantities[10];
                    int itemCount = 0;
                    char contChoice;
                    do {
                        printf("Enter item ID: ");
                        scanf("%d", &itemIds[itemCount]);
                        printf("Enter quantity: ");
                        scanf("%d", &quantities[itemCount]);
                        itemCount++;
                        printf("Do you want to add more items? (y/n): ");
                        scanf(" %c", &contChoice);
                    } while (contChoice == 'y' && itemCount < 10);

                    float totalBill = generateBill(itemIds, quantities, itemCount);
                    printf("Thank you for shopping!\n");
                    break;
                }
                case 4:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        } while (action != 4);

        free(user->username);
        free(user->password);
        free(user);
    } else {
        printf("Login failed. Exiting...\n");
    }
    return 0;
}
