#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "roles.h"
void PrintMenu(){
 printf("\n");
    printf("=====================================\n");
    printf("        Welcome to CheatDesk     \n");
    printf("=====================================\n");
    printf("  [1] Choose a role\n");
    printf("  [2] Create a new role\n");
    printf("  [5] Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
  }
int is_number(const char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}
int LoadDB(struct Roles roles[]) {
    int count = 0;
    FILE* db_file = fopen("DB.txt", "r");
    if (db_file == NULL) {
        perror("Error opening DB file");
        return 0;
    }

    char name[20];
    char filename[20];

    while (fscanf(db_file, "%19s %19s", name, filename) == 2) {
        strncpy(roles[count].Name, name, sizeof(roles[count].Name));
        strncpy(roles[count].Filename, filename, sizeof(roles[count].Filename));
        count++;
    }

    fclose(db_file);
    return count;
}

void FileCreating(char* filename) {
  char run[20];
  FILE* in_file = fopen(filename, "w");
    if (in_file == NULL) {
        perror("Error opening file");
        return;
    }
    printf("Role ' %s ' created!\n", filename);
    fclose(in_file);
    printf("Enter the '%s', script file name: ",filename);
    scanf("%s", run);
    FILE* db_file = fopen("DB.txt", "a");
    if (db_file == NULL) {
      perror("Error opening DB file");
      return;
    }
    fprintf(db_file, "\n%s %s", filename, run);
    fclose(db_file);
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

char* RoleSelector(int RoleCount, struct Roles roles[]) {
    static char role[20];
    printf("What type of request are you performing\n");
    for (int i = 0; i < RoleCount; i++) {
        printf("%d. %s\n", i + 1, roles[i].Name);
    }
    scanf("%19s", role);
    return role;
}

char* RoleCreator() {
    static char role[20];
    printf("How is the new Role called?\n");
    scanf("%19s", role);
    return role;
}
