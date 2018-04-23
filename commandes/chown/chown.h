#ifndef CHOWN_H
#define CHOWN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int chown(const char *path, uid_t owner, gid_t group);
int chowner(int argc, char *argv[]);

#endif
