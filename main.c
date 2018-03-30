//#include "interpreteur/commandEntry.h"
#include "interpreteur/commandParser.h"
#include "interpreteur/command.h"

int main(int argc, char *argv[])
{
    //Lancement de la console et de son affichage
    //return commandLine();
    char *temp = " commande1 arg1 arg2";
    int returnHandler = 0;
    commandParser *tempParser = setParser(temp);
    command *cmd;
    while ((returnHandler = parse(tempParser, &cmd)) == 1)
    {
        printCommand(cmd);
    }
    //Vérification de l'erreur
    if (returnHandler == 2)
    {
        printf("ERREUR LORS DU PARSING DE LA COMMANDE");
    }
    //Exécution des commandes
    else
    {
    }
}