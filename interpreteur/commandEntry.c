#include "commandEntry.h"

//Fonction de base d'entré de l'utilisateur
int commandLine()
{
    const size_t entrySize = 64;
    char *entry = malloc(sizeof(char) * entrySize); //Commande de l'utilsateur
    char *out;
    //Retour de l'analyse
    //Nettoyage du terminal
    initListCommands();
    system("clear");
    //Tant que l'utilisateur ne quitte pas le terminal
    do
    {
        //Code de gestion de l'affichage du terminal
        printHead();
        //Gestion des entrées utilisateurs
        fgets(entry, entrySize, stdin);
        //Envoit des commandes utilisateurs à
        analyse(entry);
    } while (1);
    return 0;
}
void printHead()
{
    struct passwd *pw;

    char *currentDir = malloc(sizeof(char) * 256);

    pw = getpwuid(getuid());
    getcwd(currentDir, 256);

    printf(GRN "%s", pw->pw_name);
    printf(WHT ":");
    printf(BLU "%s", currentDir);
    printf(RESET);
    printf("$ ");
}
