#ifndef FOCUSCOMCOMMAND_H
#define FOCUSCOMCOMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

typedef enum e_outPutMode {
    CONSOLE,
    LOGFILE,
    BASHFILE,
    NONE
} e_outPutMode;
char *logFile;
FILE *outPutFileStd;
FILE *outPutFileErr;
e_outPutMode outPutMode;
//Initialisation de la libraire
//name = nom de la commande en cours
void printOpen(const char *name);
//Fermeture de la librairie
void printClose();
//Envoit du résultat de la commande
//Agit comme un printf
int print(char *str, ...);

#endif