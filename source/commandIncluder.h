#ifndef COMMANDINCLUDER_H
#define COMMANDINCLUDER_H
#include "command.h"
#include "ls.h"
#include "cat.h"
#include "echo.h"
#include "pwd.h"
#include "rm.h"
#include "cp.h"
#include "cd.h"
#include "makedir.h"
#include "chown.h"
#include "chgrp.h"
#include "chmod.h"
#include "du.h"
#include "mv.h"

//Initialise la liste des commandes en remplissant une liste chainée avec les différentes commandes que gère le bash
void initListCommands();

#endif
