
#ifndef COMMAND_H
#define COMMAND_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"
#include "commandFunction.h"
#include "interCommunication.h"
#include <sys/wait.h>

//ENUM MODE : correspond aux différents modes d'excécution d'une commande
typedef enum MODE {
    DETACHEMENT,      // & DETACHEMENT DU TERMINAL
    REDIRECT_OUT_END, // >> SORTIE VERS FIN DE FICHIER
    REDIRECT_OUT,     // > SORTIE VERS FICHIER
    REDIRECT_IN,      // < RESULT IN
    REDIRECT_ENTRY,   // << ENTREE UTILISATEUR
    PIPE,             // | PIPE
    AND,              //&& et logique (exécution simple)
    OR,               //|| ou logique
    END,
    NONE
} MODE;
MODE findMODE(char *string);

typedef struct command
{
    char *name;
    int nbArg;
    char **arg;
    MODE mode;
} command;

struct commandList *cmdList;

//Initialise une commande vide
command *emptyCommand();

//Initialise une commande
command *initCommand(char *name, int nbArg, char **arg, MODE mode);

//Copie une commande dans une autre
void cpCommand(command *destination, command *source);

//Execute une commande cmd
int executeCommand(command *cmd);

//Execute une commande selon son mode
void executeCommandToFile(command *cmd, char *file, const char *mode);

//Execute un programme executable
void executeProgram(char *path);

//Vérifie si la chaine passée en paramètre correspond à un fichier standard executable qui existe
int isProgram(char *name);
//Vérifie si la commande existe
int exist(command *cmd);

//Retourne le chemin vers le dossier contenant les processus pour le mode processus
void setProcessPath(char *callCommand);

//Fonction de test
void printCommand(command *cmd);

#endif
