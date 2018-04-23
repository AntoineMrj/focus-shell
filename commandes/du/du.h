#ifndef DU_H
#define DU_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "../comCommunication.h"

int du(int argc, char *argv[]);
char *get_current_dir_name(void);

#endif
