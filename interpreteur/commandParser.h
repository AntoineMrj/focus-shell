#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#include "stack.h"
#include "command.h"

//Structure d'un parser
typedef struct commandParser
{
    char *chaine;//Chaine de caractère tapé par un utilisateur à analyser
    int size_chaine;//taille de la chaine
    int actualPosition;//position actuelle dans la chaine
    commandStack parsedCommandStack;

} commandParser;

//Initialise un parser
void setParser(commandParser *parser, char *chaine, int size_chaine);
//Lit une commande d'un parser
//renvoit 1 quand une commande est parser
//0 quand il n'y plus de commande à parser
//Stocke les commandes trouvé dans cmd
int parse(commandParser *parser, command *cmd);

#endif