#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roles.h"

int main(void) {
    int choice;
    struct Roles roles[MAX_ROLES];

    int RoleCount=LoadDB(roles);
    while (1) {
       PrintMenu();
        scanf("%d",&choice);
        getchar();
        if (choice == 1) {
            char *SelectedRoles = RoleSelector(RoleCount, roles);
            char command[100];

            if (is_number(SelectedRoles)) {
                int index = atoi(SelectedRoles)-1;
                if (index >= 0 && index < RoleCount) {
                    sprintf(command, "python %s", roles[index].Filename);
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
        //TBD
        }
        else if (choice ==5) {
            return 0;
        }
    }
}
