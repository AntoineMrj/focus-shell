#ifndef COMINTERPRETEUR_H
#define COMINTERPRETEUR_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
typedef enum e_envMode {
    CONSOLE,
    BASHFILE
} e_envMode;
//Initialise l'environment de communication du shell
void initEnv();
//Choisit le mode de communication des résultats
void setEnvMode(e_envMode mode);
char **getEnv();
//Fermeture de l'environment de communication en supprimant les fichiers
void closeEnvironment();
//Récupère le contenu du fichier de communication
char *getFile(char *file);
char *getStd();
char *getErr();
void readStd();
void readErr();
void readLog();
int hasErr();
int hasStd();
int hasLog();

void flushStd();
void flushErr();
void flush();
void flushLog();

#endif