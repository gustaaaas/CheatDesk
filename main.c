#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Roles {
    char Name[20];
    char FileName[20];
};


char* RoleSelector(int RoleCount,  struct Roles roles[]);
char* RoleCreator();
void FilePrinting(char* filename);
void FileCreating(char* filename);
//add a menu.c a header file also a function file. also a nice ASCII art for the main menu would be nice
//need to finish with the Roles struct to fully implement it!!!

#define MAX_ROLES 100

int main(void) {
    int RoleCount = 0 , choice;
    struct Roles roles[MAX_ROLES];
    while (1) {
        printf("Welcome to CheatDesk\n");
        printf("Do you want to choose a role (1)?\nDo you want to create a role (2)?\n");
        scanf("%d",&choice);
        if (choice == 1) {
            char* SelectedRoles = RoleSelector(RoleCount, roles);
            char filename[50];
            sprintf(filename,"%s.txt",SelectedRoles);
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
        else if (choice ==5) {
            return 0;
        }
    }
}
void FileCreating(char* filename) {
    FILE* in_file = fopen(filename, "w");
    if (in_file == NULL) {
        perror("Error opening file");
        return;
    }
    printf("Role ' %s ' created!\n", filename);
    fclose(in_file);
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
char* RoleSelector(int RoleCount,struct Roles roles[]) {
    static char role[20];
    printf("What type of request are you performing\n");
    for (int i = 0; i < RoleCount; i++) {
        printf("%d. %s\n", i + 1, roles[i].Name);
    }
    scanf("%19s",role);
    return role;
}
char* RoleCreator() {
    static char role[20];
    printf("How is the new Role called?\n");
    scanf("%19s",role);
    return role;
}