#include <stdio.h>
#include <stdlib.h>
char* RoleSelector();
char* RoleCreator();
void FilePrinting();
//add a menu.c a header file also a function file. also a nice ASCII art for the main menu would be nice

int main(void) {

    printf("Welcome to CheatDesk\n");
    int choice;

    printf("Do you want to choose a role (1)?\nDo you want to create a role (2)?\n");
    scanf("%d",&choice);
    if (choice == 1) {
        char* Roles=RoleSelector();
        char filename[50];
        sprintf(filename,"%s.txt",Roles);
        FilePrinting(filename);
    }
    else if (choice == 2) {
        char* Roles=RoleCreator();
        char filename[50];
    }
    return 0;
}
void FilePrinting(char* filename) {
    FILE* in_file = fopen(filename, "r");
    if (in_file == NULL) {
        perror("Error opening file");
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), in_file)) {
        printf("%s", buffer);
    }
    fclose(in_file);
}
char* RoleSelector() {
    static char role[20];
    printf("What type of request are you performing");
    printf("\n1. SWL\n2. NA\n");
    scanf("%19s",role);
    return role;
}
char* RoleCreator() {
    static char role[20];
    printf("How is the new Role called?\n");
    scanf("%19s",role);
    return role;
}