#include <stdio.h>
#include <stdlib.h>
char* RoleSelector();

int main(void) {
    printf("Welcome to CheatDesk\n");
    char* Roles=RoleSelector();
    char filename[50];
    sprintf(filename,"%s.txt",Roles);
    FILE* in_file = fopen(filename, "r");
    if (in_file == NULL) {
        perror("Error opening file");
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), in_file)) {
        printf("%s", buffer);
    }

    fclose(in_file);



    return 0;
}
char* RoleSelector() {
    static char* role[20];
    printf("What type of request are you performing");
    printf("\n1. SWL\n2. NA\n");
    scanf("%19s",role);
    return role;
}