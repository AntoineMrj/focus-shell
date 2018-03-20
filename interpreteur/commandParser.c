
#include "commandParser.h"


//Initialise un parser
void setParser(commandParser *parser, char *chaine, int size_chaine)
{
    
}

//Lit une commande d'un parser
//renvoit 1 quand une commande est parser
//0 quand il n'y plus de commande à parser
//Stocke les commandes trouvé dans cmd
int parse(commandParser *parser, command *cmd)
{
    //Parse la chaine associé au parser
    //Une fois un symbole de fin de commande trouvé ('<','|','&','&&',...) ou qu'on atteint la fin de la chaine
    //Création initialisation de cmd avec les arguments trouvé
    //retourne 1 si la chaine n'est pas encore vide ou vient juste d'être vidé
    //0 sinon
}
