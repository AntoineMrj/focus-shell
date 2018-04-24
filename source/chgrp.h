#ifndef CHGRP_H
#define CHGRP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <grp.h>
#include "comCommunication.h"

int chown(const char *path, uid_t owner, gid_t group);
void chgrp(int argc, char *argv[]);

#endif
