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
#include "mkdir.h"

//Initialise la liste des commandes en remplissant une liste chainée avec les différentes commandes que gère le bash
void initListCommands();

#endif
