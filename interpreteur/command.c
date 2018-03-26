#include "command.h"

command initCommand(char *name, int nbArg, char **arg, MODE mode)
{
    command *temp = malloc(sizeof(command));
    temp->name = name;
    temp->nbArg = nbArg;
    strcpy(temp->arg, arg);
    temp->mode = mode;

    return *temp;
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
    else
    {
        return NONE;
    }
}
//Execute une commande cmd
int executeCommand(command *cmd)
{
    //Exécute une command selon son mode
    //Récupération de son résultat dans un result
    //retour du result
}

//Fonction de test
void printCommand(command *cmd)
{
    printf("nb arg : %s\n", cmd->name);
    printf("nb arg : %i\n", cmd->nbArg);
    for (int i = 0; i < cmd->nbArg; i++)
    {
        printf("arg %i = %s \n", i, cmd->arg[i]);
    }
}