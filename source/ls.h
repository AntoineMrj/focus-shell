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
void show_file_info(char *filename, struct stat *info_p);
void mode_to_letters(int mode, char str[]);
char *uid_to_name(uid_t uid);
char *gid_to_name(gid_t gid);
char *ctime();

#endif
