#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

User *loginUser() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int i = 0;

    printf("Enter username: ");
    scanf("%49s", username);
    printf("Enter password: ");
    scanf("%49s", password);

    User *user = (User *)malloc(sizeof(User));
    if (user == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (i = 0; i < MAX_LENGTH && username[i] != '\0'; ++i) {
        user->username[i] = username[i];
    }
    user->username[i] = '\0';

    for (i = 0; i < MAX_LENGTH && password[i] != '\0'; ++i) {
        user->password[i] = password[i];
    }
    user->password[i] = '\0';

    return user;
}

void createUser(char *username, char *password) {
    printf("User created successfully!\n");
}
