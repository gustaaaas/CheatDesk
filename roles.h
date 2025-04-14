#ifndef ROLES_H
#define ROLES_H
#define MAX_ROLES 100
struct Roles {
  char Name[20];
  char Filename[20];
};

int LoadDB(struct Roles roles[]);
char* RoleSelector(int RoleCount, struct Roles roles[]);
char* RoleCreator();
void FilePrinting(char* filename);
void FileCreating(char* filename);

#endif
