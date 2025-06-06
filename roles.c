#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "roles.h"
#include "cheatdesk_theme.h"
void Intro() {
    printf("\033[1;36m");
    printf("    .oooooo.   oooo                                .   oooooooooo.                       oooo \n");
    printf("  d8P'  `Y8b  `888                              .o8   `888'   `Y8b                       `888\n");
    printf(" 888           888 .oo.    .ooooo.   .oooo.   .o888oo  888      888  .ooooo.     .oooo.o  888  oooo\n");
    printf(" 888           888P*Y88b  d88' `88b `P  )88b    888    888      888 d88' `88b   d88(  *8  888 .8P'\n");
    printf(" 888           888   888  888ooo888  .oP*888    888    888      888 888ooo888   `*Y88b.   888888.\n");
    printf(" `88b    ooo   888   888  888    .o d8(  888    888 .  888     d88' 888    .o   o.  )88b  888 `88b.\n");
    printf("  `Y8bood8P'  o888o o888o `Y8bod8P' `Y888**8o   *888* o888bood8P'   `Y8bod8P'   8**888P' o888o o888o\n");
    printf("\033[0m\n\n\n\n\n\n");
}
void PrintMenu() {
    printf("\033[1;36m");
printf("\n|==============================|\n");
printf("|        CheatDesk Menu        |\n");
printf("|==============================|\n");
printf("|"BLUE" 1. View Roles"RESET);
printf("\033[1;36m");
printf("                |\n");
printf("|"BLUE" 2. Create Role"RESET);
printf("\033[1;36m");
printf("               |\n");
printf("|                              |\n");
printf("|"RED" 5. Exit"RESET);
           printf("\033[1;36m");
printf("                      |\n");
printf("|==============================|\n");
    printf("\033[0m");
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
    printf(GREEN "Role ' %s ' created!\n" RESET, filename);
    fclose(in_file);
    printf(YELLOW "Enter the '%s', script file name: " RESET,filename);
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
        perror(RED "Error opening file" RESET);
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
    printf(YELLOW "What type of request are you performing\n" RESET);
    for (int i = 0; i < RoleCount; i++) {
        printf(BLUE "%d. %s\n" RESET, i + 1, roles[i].Name);
    }
    scanf("%19s", role);
    return role;
}

char* RoleCreator() {
    static char role[20];
    printf(YELLOW "How is the new Role called?\n" RESET);
    scanf("%19s", role);
    return role;
}
