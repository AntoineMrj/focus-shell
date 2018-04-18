#include "commandManager.h"

//Envoit la chaine de caractère à un parser pour l'analyser
void analyse(char *argv)
{
    //Lancement de la console et de son affichage
    //return commandLine();
    int returnHandler = 0;
    commandParser *tempParser = setParser(argv);
    command *cmd;
    while ((returnHandler = parse(tempParser, &cmd)) == 1)
    {
        returnHandler = executeCommand(cmd);
    }
    //Vérification de l'erreur
    if (returnHandler == 2)
    {
        printf("ERREUR LORS DU PARSING DE LA COMMANDE\n");
    }
    //Exécution des commandes
    else
    {
    }
    //Création et initialisation d'un parser
    //Création d'un stack de commande
    //Tant que l'on peut parser on continue
    //Parcours et Switch case sur le type de commande
    //soit une exécution direct (fin de ligne ou &&) et exécution des commandes contenues dans la pile si non vide
    //avec ou sans redirection de ses flux
    //soit ajout dans une stack pour être exécuter plus tard (gestion des redirections d'entrées)
    //soit fork et exécution des commandes contenues dans la pile si non vide
    //soit gestion du pipe
    //retour du résultat de la commande
    //result de la commande si pas de redirection de flux
    //erreur si erreur lors du parsing
}