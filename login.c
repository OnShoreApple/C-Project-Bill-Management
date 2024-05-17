#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_FILE "users.txt"

typedef struct {
    char* username;
    char* password;
} User;

User* loginUser() {
    char inputUsername[50];
    char inputPassword[50];
    FILE *file = fopen(USER_FILE, "r");

    if (file == NULL) {
        printf("Error opening user file.\n");
        return NULL;
    }

    printf("Enter username: ");
    scanf("%s", inputUsername);
    printf("Enter password: ");
    scanf("%s", inputPassword);

    User* user = malloc(sizeof(User));
    if (user == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    user->username = malloc(50 * sizeof(char));
    user->password = malloc(50 * sizeof(char));

    if (user->username == NULL || user->password == NULL) {
        printf("Memory allocation failed.\n");
        free(user);
        fclose(file);
        return NULL;
    }

    while (fscanf(file, "%s %s", user->username, user->password) != EOF) {
        if (strcmp(user->username, inputUsername) == 0 && strcmp(user->password, inputPassword) == 0) {
            printf("Login successful!\n");
            fclose(file);
            return user;
        }
    }

    printf("Login failed. User does not exist.\n");
    free(user->username);
    free(user->password);
    free(user);
    fclose(file);
    return NULL;
}

void createUser() {
    char username[50];
    char password[50];
    FILE *file = fopen(USER_FILE, "a");

    if (file == NULL) {
        printf("Error opening user file.\n");
        return;
    }

    printf("Enter new username: ");
    scanf("%s", username);
    printf("Enter new password: ");
    scanf("%s", password);

    fprintf(file, "%s %s\n", username, password);
    printf("User created successfully!\n");
    fclose(file);
}
