#include "commandIncluder.h"
//Initialise la liste des commandes en remplissant une liste chainée avec les différentes commandes
void initListCommands()
{
    //création d'une liste chainée
    cmdList = initList();
    addCmdIdentifier(cmdList, "ls", ls);
    addCmdIdentifier(cmdList, "cat", cat);
    addCmdIdentifier(cmdList, "rm", rm);
    addCmdIdentifier(cmdList, "echo", echo);
    addCmdIdentifier(cmdList, "pwd", pwd);
    addCmdIdentifier(cmdList, "cp", cp);
    addCmdIdentifier(cmdList, "cd", cd);
    addCmdIdentifier(cmdList, "mkdir", mkdir);
    addCmdIdentifier(cmdList, "chown", mkdir);
    addCmdIdentifier(cmdList, "chgrp", mkdir);
    addCmdIdentifier(cmdList, "chmod", mkdir);
    addCmdIdentifier(cmdList, "du", mkdir);
    return 1;
}