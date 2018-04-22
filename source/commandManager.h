#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H
#include "command.h"
#include "commandParser.h"
#include "interCommunication.h"
#include "queue.h"
#include "printColor.h"

//Envoit la chaine de caractère à un parser pour l'analyser
void analyse(char *argv);

//Execute les commandes contenues dans la cmdQueue
void executeQueue(commandQueue *cmdQueue, int hasToFlush, int readOut);

//Recupère les données entrées par l'utilisateur
char *getUserEntry(char *endString);

#endif
