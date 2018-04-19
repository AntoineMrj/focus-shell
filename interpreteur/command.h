
#ifndef COMMAND_H
#define COMMAND_H
#include <string.h>
#include "commandIncluder.h"
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"
#include "commandFunction.h"

//ENUM MODE : correspond au différent mode d'excécution d'une commande
typedef enum MODE {
    DETACHEMENT,      // & DETACHMENT DU TERMINAL
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

//Initialise une commande vide
command *emptyCommand();

//Initialise une command
command *initCommand(char *name, int nbArg, char **arg, MODE mode);
//Initialise une command
void cpCommand(command *destination, command *source);
//Execute une commande cmd
int executeCommand(command *cmd);

//Initialise la liste des commandes en remplissant une liste chainée avec les différentes commandes
void initListCommands();
struct commandList *cmdList;
//Fonction de test
void printCommand(command *cmd);

#endif
