#ifndef COMINTERPRETEUR_H
#define COMINTERPRETEUR_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

typedef enum e_envMode {
    CONSOLE,
    LOGFILE,
    BASHFILE
} e_envMode;

//Initialise l'environment de communication du shell
void initEnv();
//Choisit le mode de communication des résultats
void setEnvMode(e_envMode mode);

char **getEnv();
//Fermeture de l'environment de communication en supprimant le fichier
void closeEnvironment();
//Récupère le contenu du fichier de communication
char *readStd();
char *readErr();
#endif