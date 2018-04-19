#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H
#include "command.h"
#include "commandParser.h"
#include "interCommunication.h"
#include "queue.h"
//Envoit la chaine de caractère à un parser pour l'analyser
void analyse(char *argv);
void executeQueue(commandQueue *cmdQueue, int hasToFlush, int readOut);
char *getUserEntry(char *endString);
#endif