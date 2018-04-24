#include "commandEntry.h"

//Fonction de base d'entrée de l'utilisateur
int commandLine()
{
    const size_t entrySize = 64;
    char *entry = malloc(sizeof(char) * entrySize); //Commande de l'utilsateur
    initEnv();
    setEnvMode(BASHFILE);
    system("clear");
    //Tant que l'utilisateur ne quitte pas le terminal
    do
    {
        //Code de gestion de l'affichage du terminal
        printHead();
        //Gestion des entrées utilisateur
        fgets(entry, entrySize, stdin);
        //Envoit des commandes utilisateur
        analyse(entry);
    } while (1);
    closeEnvironment();
    return 0;
}

//Gère l'affichage du terminal (affichage du path du dossier courant)
void printHead()
{
    struct passwd *pw;

    char *currentDir = malloc(sizeof(char) * 256);
    char *hostName = malloc(sizeof(char) * 64);
    pw = getpwuid(getuid());
    getcwd(currentDir, 256);
    gethostname(hostName, 64);
    printf(GRN "%s@%s", pw->pw_name, hostName);
    printf(WHT ":");
    printf(BLU "%s", currentDir);
    printf(RESET);
    printf("$ ");
}