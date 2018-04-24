#ifndef COMMANDENTRY_H
#define COMMANDENTRY_H
#include "commandManager.h"
#include <pwd.h>
#include "interCommunication.h"
#include "printColor.h"

//Fonction de base d'entrée de l'utilisateur
int commandLine();

//Gère l'affichage du terminal (affichage du path du dossier courant)
void printHead();

void sig_handler(int signo);

#endif
