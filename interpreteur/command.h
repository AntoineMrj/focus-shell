
#ifndef COMMAND_H
#define COMMAND_H
#include "result.h"
#include "string.h"
#include "../commandes/ls/ls.h"
#include "stdlib.h"
#include "stdio.h"
#include "linkedList.h"

//prototype des fonction utiliser pour les commandes
typedef int (*cmdFunction)(int argc, char *argv[]);

//ENUM MODE : correspond au différent mode d'excécution d'une commande
typedef enum MODE {
    DETACHEMENT,      // & DETACHMENT DU TERMINAL
    REDIRECT_OUT_END, // >> SORTIE VERS FIN DE FICHIER
    REDIRECT_OUT,     // > SORTIE VERS FICHIER
    REDIRECT_IN,      // < RESULT IN
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

//Structure identifiant une commande par une chaine de caractère
typedef struct cmdIdentifier
{
    cmdFunction function;
    char *name;
} cmdIdentifier;

//Initialise une command
command *initCommand(char *name, int nbArg, char **arg, MODE mode);
//Initialise une command
void cpCommand(command *destination, command *source);
//Execute une commande cmd
int executeCommand(command *cmd);

//Initialise la liste des commandes en remplissant une liste chainée avec les différentes commandes
commandList *initListCommands();

//Fonction de test
void printCommand(command *cmd);

#endif
