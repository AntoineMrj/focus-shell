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

        return REDIRECT_ENTRY;
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
    else if (strcmp(string, ";") == 0)
    {
        return NONE;
    }
    else
    {
        return NONE;
    }
}
//Execute une commande cmd
int executeCommand(command *cmd)
{
    cmdFunction temp = find(cmdList, cmd->name);
    if (temp != NULL)
    {
        temp(cmd->nbArg, cmd->arg);
        return 1;
    }
    else
    {
        if (isProgram(cmd->name)) //si la commande est en fait un programme
        {
            executeProgram(cmd->name); //on execute le programme
            return 1;
        }
        else
        {
            printf("ERREUR : cette commande n'existe pas\n");
            return 0;
        }
    }
    //Exécute une command selon son mode
}
void executeCommandToFile(command *cmd, char *file, const char *mode)
{
    FILE *out;
    executeCommand(cmd);
    out = fopen(file, mode);
    fprintf(out, "%s", getStd());
    fclose(out);
}
void executeProgram(char *path)
{
    char *args[] = {path, NULL};

    int pid = fork(); //on fait un fork pour executer le programme sans stoper le bash

    if (pid > 0) //Code du processus pere
    {
        int statut;
        wait(&statut);
        /*printf("==== PERE ====\n");
      printf("PID : %d\n",getpid());
      printf("PPID : %d\n",getppid());*/
    }
    else
    {
        if (pid == 0 && execv(path, args) == -1)
        { //Code du processus fils
            /*printf("==== FILS ====\n");
        printf("PID : %d\n",getpid());
        printf("PPID : %d\n",getppid());*/
            printf("Erreur le fichier n'a pas pu se lancer \n");
        }
        else
        {
            printf("ERREUR de fork\n");
        }
    }
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
