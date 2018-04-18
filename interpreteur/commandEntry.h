#ifndef COMMANDENTRY_H
#define COMMANDENTRY_H
#include "commandManager.h"
#include <pwd.h>
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"
//Fonction de base d'entré de l'utilisateur
int commandLine();
void printHead();

#endif