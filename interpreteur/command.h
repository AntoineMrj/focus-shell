
#ifndef COMMAND_H
#define COMMAND_H
#include "result.h"
#include "../commandes/ls.h"
//ENUM MODE : correspond au différent mode d'excécution d'une commande
typedef enum MODE {
    DETACHEMENT,      // & DETACHMENT DU TERMINAL
    REDIRECT_OUT_END, // >> SORTIE VERS FIN DE FICHIER
    REDIRECT_OUT,     // > SORTIE VERS FICHIER
    REDIRECT_IN,      // < RESULT IN
    REDIRECT_IN,      // << USER IN
    PIPE,             // | PIPE
    AND,            //&& et logique (exécution simple)
    OR            //|| ou logique
} MODE;

typedef struct command
{
    char *name;
    int nbArg;
    char *arg;
    MODE mode;
} command;

//Structure identifiant une commande par une chaine de caractère
typedef struct cmdIdentifier
{
    cmdFunction function;
    char *name;
} cmdIdentifier;

//Initialise une command
command initCommand(char *name, int nbArg, char *arg, MODE mode);
//Execute une commande cmd
int executeCommand(command *cmd);

#endif
