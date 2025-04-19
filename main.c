#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roles.h"

int main(void) {
    int choice;
    struct Roles roles[MAX_ROLES];

    int RoleCount=LoadDB(roles);

    printf("Welcome to CheatDesk\n");
    while (1) {
        printf("Choose a role (1)?\nDo you want to create a role (2)?\nExit(5)\n");
        scanf("%d",&choice);
        if (choice == 1) {
            char *SelectedRoles = RoleSelector(RoleCount, roles);
            char command[100];

            if (is_number(SelectedRoles)) {
                int index = atoi(SelectedRoles);
                if (index >= 0 && index < RoleCount) {
                    sprintf(command, "python %s", roles[index-1].Filename);
                } else {
                    printf("Invalid index.\n");
                    continue;
                }
            } else {
                sprintf(command, "python %s", SelectedRoles);
            }

            printf("Running: %s\n", command);
            int launch = system(command);
        }
        else if (choice == 2) {
            char* Roles=RoleCreator();
            strcpy(roles[RoleCount].Name,Roles);
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
