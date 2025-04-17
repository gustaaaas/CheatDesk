#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roles.h"

int main(void) {
    int choice;
    struct Roles roles[MAX_ROLES];

    int RoleCount=LoadDB(roles);
    while (1) {
        printf("Welcome to CheatDesk\n");
        printf("Do you want to choose a role (1)?\nDo you want to create a role (2)?\nExit(5)\n");
        scanf("%d",&choice);
        if (choice == 1) {
            char* SelectedRoles = RoleSelector(RoleCount, roles);
            char filename[50];
            sprintf(filename,"%s.txt",SelectedRoles);
            FilePrinting(filename);
            printf("Launch Documentation Builder (1)\n Go back (2)\n");
            scanf("%d",&choice);
                if (choice == 1) {
                    int launch=system("Roles.py");
                }
                else continue;
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
