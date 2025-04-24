#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "roles.h"
#include "cheatdesk_theme.h"
void warmUpConsole() {
    fflush(stdout);
    Sleep(300);
}
int main(void) {
    int doesntmatter=0;
    warmUpConsole();
    printf("\nPress (1) and then enter\n");
    scanf("%s", &doesntmatter);
    system("cls");
    int choice;
    struct Roles roles[MAX_ROLES];

    int RoleCount = LoadDB(roles);
    Intro();
    while (1) {
        PrintMenu();
        scanf("%d",&choice);
        getchar();
        if (choice == 1) {
            system("cls");
            char *SelectedRoles = RoleSelector(RoleCount, roles);
            char command[100];

            if (is_number(SelectedRoles)) {
                int index = atoi(SelectedRoles)-1;
                if (index >= 0 && index < RoleCount) {
                    sprintf(command, "%s", roles[index].Filename);
                } else {
                    printf(RED "Invalid index.\n" RESET);
                    continue;
                }
            } else {
                sprintf(command, "%s", SelectedRoles);
            }

            printf(RED"Running: %s\n \n loading...\n\n"RESET, command);
            int launch = system(command);
        }
        else if (choice == 2) {
            system("cls");
            char* Roles=RoleCreator();
            strcpy(roles[RoleCount].Name,Roles);
            FileCreating(Roles);
            RoleCount++;
        }
        else if (choice == 3) {
        //nesugalvojau dar
        }
        else if (choice ==5) {
            return 0;
        }
    }
}
