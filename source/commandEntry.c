#include "commandEntry.h"

//Fonction de base d'entré de l'utilisateur
int commandLine()
{
    const size_t entrySize = 64;
    char *entry = malloc(sizeof(char) * entrySize); //Commande de l'utilsateur
    //Retour de l'analyse
    //Nettoyage du terminal
    //system("clear");
    initEnv();
    setEnvMode(BASHFILE);
    initListCommands();
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
    closeEnvironment();
    return 0;
}
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
