#ifndef MKDIR_H
#define MKDIR_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include "comCommunication.h"

void makedir(int argc, char *argv[]);

#endif
