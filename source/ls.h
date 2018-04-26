#ifndef LS_H
#define LS_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include "comCommunication.h"
#include "printColor.h"

void ls(int argc, char *argv[]);
void parcoursDossier(int a, int l, char *repertoire_courant);
void show_file_info(char *, struct stat *);
void mode_to_letters(int, char[]);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);

#endif
