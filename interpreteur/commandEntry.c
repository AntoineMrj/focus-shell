#include "commandEntry.h"

//Fonction de base d'entré de l'utilisateur
int commandLine()
{
    char* entry=malloc(sizeof(char)*64) ;//Commande de l'utilsateur
    char* out;//Retour de l'analyse
    //Nettoyage du terminal
    initListCommands();
    system("clear");
    //Tant que l'utilisateur ne quitte pas le terminal
    while(1)
    {
        //Code de gestion de l'affichage du terminal 
        printHead();  
        //Gestion des entrées utilisateurs
        scanf("%s",entry);

        //Envoit des commandes utilisateurs à 
        analyse(entry);
    }
    return 0;
}
int printHead()
{
    struct passwd *pw;

    char currentDir[64];
    char* currentUser;

    pw = getpwuid(getuid());
     getcwd(currentDir,64);


    //printf("\n%s:%s:>",pw->pw_name,currentDir);
    printf("\n%s:>",pw->pw_name);
}
