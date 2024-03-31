#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

int userExists(char *username) {
    return 0;
}

void createUser(char *username, char *password) {
    printf("User created successfully!\n");
}

int verifyLogin(char *username, char *password) {
    return 1;
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    if (userExists(username)) {
        printf("Enter password: ");
        scanf("%s", password);
        if (verifyLogin(username, password)) {
            printf("Login successful!\n");
            return 1;
        } else {
            printf("Invalid password.\n");
            return 0;
        }
    }
    else {
        printf("User does not exist. Creating new account...\n");
        printf("Enter password for new account: ");
        scanf("%s", password);
        createUser(username, password);
        return 1;
    }
}
