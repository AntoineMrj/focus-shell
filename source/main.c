#include "commandEntry.h"
#include "commandIncluder.h"
int main()
{
    //Lancement de la console et de son affichage
    initListCommands();
    return commandLine();
}