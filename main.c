#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* RoleSelector();
char* RoleCreator();
void FilePrinting();
void FileCreating();
//add a menu.c a header file also a function file. also a nice ASCII art for the main menu would be nice
//need to finish with the Roles struct to fully implement it!!!
struct Roles {
    char Name[20];
    char FileName[20];
};
#define MAX_ROLES 100

int main(void) {
    int RoleCount = 0 , choice;
    struct Roles roles[MAX_ROLES];

    printf("Welcome to CheatDesk\n");
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
        strcpy(roles[RoleCount].Name,Roles);
        //printf("%s\n",roles[RoleCount].Name);
        FileCreating(Roles);
        RoleCount++;
    }
    else if (choice == 3) {

    }
    return 0;
}
void FileCreating(char* filename) {
    FILE* in_file = fopen(filename, "w");
    if (in_file == NULL) {
        perror("Error opening file");
        return;
    }
    printf("Role ' %s ' created!\n", filename);
}
void FilePrinting(char* filename) {
    FILE* in_file = fopen(filename, "r");
    if (in_file == NULL) {
        perror("Error opening file");
        return;
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
    //will need to modify this to dinamicly show the names
    printf("\n1. SWL\n2. HRL\n");
    scanf("%19s",role);
    return role;
}
char* RoleCreator() {
    static char role[20];
    printf("How is the new Role called?\n");
    scanf("%19s",role);
    return role;
}