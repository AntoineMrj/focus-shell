#include "commandManager.h"

//Envoit la chaine de caractère à un parser pour l'analyser
char *analyse(char *argv)
{
    //Création et initialisation d'un parser
    //Création d'un stack de commande
    //Tant que l'on peut parser on continue
        //Switch case sur le type de commande
            //soit une exécution direct (fin de ligne ou &&) et exécution des commandes contenues dans la pile si non vide
                //avec ou sans redirection de ses flux
            //soit ajout dans une stack pour être exécuter plus tard (gestion des redirections d'entrées)
            //soit fork et exécution des commandes contenues dans la pile si non vide
            //soit gestion du pipe 
    //retour du résultat de la commande 
        //result de la commande si pas de redirection de flux
        //erreur si erreur lors du parsing
}