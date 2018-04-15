#include "command.h"

command *initCommand(char *name, int nbArg, char **arg, MODE mode)
{
    command *temp = malloc(sizeof(command));
    temp->name = malloc(sizeof(char) * strlen(name));
    strcpy(temp->name, name);
    temp->nbArg = nbArg;
    temp->arg = malloc(sizeof(char *) * nbArg);
    for (int i = 0; i < nbArg; i++)
    {
        temp->arg[i] = malloc(sizeof(char) * strlen(arg[i]));
        strcpy(temp->arg[i], arg[i]);
    }

    temp->mode = mode;
    return temp;
}
void cpCommand(command *destination, command *source)
{
    destination->arg = source->arg;
    destination->name = source->name;
    destination->nbArg = source->nbArg;
    destination->mode = source->mode;
}
MODE findMODE(char *string)
{

    if (strcmp(string, "&") == 0)
    {
        return DETACHEMENT;
    }
    else if (strcmp(string, ">>") == 0)
    {
        return REDIRECT_OUT_END;
    }
    else if (strcmp(string, ">") == 0)
    {
        return REDIRECT_OUT;
    }
    else if (strcmp(string, "<") == 0)
    {
        return REDIRECT_IN;
    }
    else if (strcmp(string, "<<") == 0)
    {
        return REDIRECT_IN;
    }
    else if (strcmp(string, "|") == 0)
    {
        return PIPE;
    }
    else if (strcmp(string, "&&") == 0)
    {
        return AND;
    }
    else if (strcmp(string, "||") == 0)
    {
        return OR;
    }
    else if (strcmp(string, "\0") == 0)
    {
        return END;
    }
    else
    {
        return NONE;
    }
}
//Execute une commande cmd
int executeCommand(command *cmd)
{
    //Exécute une command selon son mode
}

//Initialise la liste des commandes en remplissant une liste chainée avec les différentes commandes
commandList *initListCommands()
{
  //création d'une liste chainée
  commandList *list = initList();

  //déclaration du pointeur qui va contenir les fonctions une à une
  int (*cmdFunction)(int argc, char *argv[]);

  //création des cmdIdentifier
  cmdIdentifier *newCmdIdentifier = malloc(sizeof(cmdIdentifier));
  cmdFunction = ls;
  newCmdIdentifier->function = cmdFunction;
  newCmdIdentifier->name = "ls";

  //ajout de la cellule
  add(list, newCmdIdentifier);

  /*
  .
  . On fait pareil pour chaque fonction, il faudra faire une boucle, j'attend de voir si ça marche avec 'ls'
  .
  */

  return list;
}

//Fonction de test
void printCommand(command *cmd)
{
    printf("\ncommande : %s\n", cmd->name);
    printf("nb arg : %i\n", cmd->nbArg);
    for (int i = 0; i < cmd->nbArg; i++)
    {
        printf("arg %i = %s \n", i + 1, cmd->arg[i]);
    }
}
