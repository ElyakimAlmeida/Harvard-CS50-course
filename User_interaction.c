#include <stdio.h>
#include <stdlib.h>
#include <string.h>#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(message) printf("%s: %s\n", __func__, message)

int main(void) {
    char name[100];  // define the variable as a string with 100 characters maximum
    LOG("Program started");
    printf("Welcome to my first program in C!\n");
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin); 
    name[strcspn(name, "\n")] = '\0';
    LOG("User input received");
    printf("Hello, %s!\n", name);
    LOG("Program completed");

    return 0;
}

int main(void) {
    char name[100];  // define the variable as a string with 100 characters maximum
    printf("Welcome to my first program in C!\n");
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin); 
    name[strcspn(name, "\n")] = '\0';
    printf("Hello, %s!\n", name);

    return 0;
}
