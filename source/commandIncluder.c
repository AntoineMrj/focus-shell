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
    addCmdIdentifier(cmdList, "mkdir", makedir);
    addCmdIdentifier(cmdList, "chown", chowner);
    addCmdIdentifier(cmdList, "chgrp", chgrp);
    addCmdIdentifier(cmdList, "chmod", chmode);
    addCmdIdentifier(cmdList, "du", du);
}