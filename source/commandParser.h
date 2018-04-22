#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H
#define CARACSIZE 1024
#include "command.h"

typedef enum STATE {
    WAIT,    // & DETACHMENT DU TERMINAL
    PARSING, // >> SORTIE VERS FIN DE FICHIER
    ENDPARSING
} STATE;

//Structure d'un parser
typedef struct commandParser
{
    char *chaine;       //Chaine de caractère tapé par un utilisateur à analyser
    int actualPosition; //position actuelle dans la chaine
    int hasEnded;
    STATE state;
} commandParser;

//Initialise un parser
commandParser *setParser(char *chaine);

//Lit une commande d'un parser
//renvoit 1 quand une commande est parser
//0 quand il n'y plus de commande à parser
//Stocke les commandes trouvé dans cmd
int parse(commandParser *parser, command **cmd);

//Ajoute un \0 à la fin de la chaîne pour la "normaliser"
void normaliseStr(char *chaine);

#endif
