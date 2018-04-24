#include "commandIncluder.h"

//Initialise la liste des commandes en remplissant une liste chainée avec les différentes commandes
void initListCommands()
{
    //création d'une liste chainée
    cmdList = initList();
    addCmdIdentifier(cmdList, "cd", cd);

}
