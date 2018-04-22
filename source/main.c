#include "commandEntry.h"
#include "commandIncluder.h"
int main(int argc, char *argv[])
{
    //Lancement de la console et de son affichage
    if (argc >= 1)
        setProcessPath(argv[0]);
    initListCommands();
    return commandLine();
}