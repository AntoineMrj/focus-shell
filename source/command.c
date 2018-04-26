#include "command.h"
char *processPath;
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
    optind = 1;
    cmdFunction temp = find(cmdList, cmd->name);
    if (temp != NULL)
    {
        temp(cmd->nbArg, cmd->arg);
        return 1;
    }
    else
    {
        char *tempFile = malloc(sizeof(char) * 512);
        strcpy(tempFile, processPath);
        strcat(tempFile, cmd->name);
        if (isProgram(cmd->name)) //si la commande est en fait un programme
        {
            executeProgram(cmd->name); //on execute le programme
            return 1;
        }
        else if (isProgram(tempFile)) //si la commande est un processus
        {
            executeProgram(tempFile); //on execute le processus
            return 1;
        }
        else
        {
            printf("ERREUR : cette commande ou processus n'existe pas\n");
            return 0;
        }
    }
}
int exist(command *cmd)
{
    if (find(cmdList, cmd->name) != NULL)
    {
        return 1;
    }
    else
    {
        char *tempFile = malloc(sizeof(char) * 512);
        strcpy(tempFile, processPath);
        strcat(tempFile, cmd->name);
        if (isProgram(cmd->name)) //si la commande est en fait un programme
        {
            return 1;
        }
        else if (isProgram(tempFile)) //si la commande est un processus
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int isText(command *cmd)
{
    if (cmd->mode == REDIRECT_ENTRY || cmd->mode == REDIRECT_OUT || cmd->mode == REDIRECT_OUT_END)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Execute une commande selon son mode
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

    int pid = fork(); //on fait un fork pour executer le programme sans stopper le bash

    if (pid > 0) //Code du processus pere
    {
        int statut;
        wait(&statut);
    }
    else
    {
        if (pid == 0 && execv(path, args) == -1)
        {
            printf("ERREUR : le fichier n'a pas pu se lancer \n");
        }
        else
        {
            printf("ERREUR : erreur de fork\n");
        }
    }
}

//Vérifie si la chaine passée en paramètre correspond à un fichier standard executable qui existe
int isProgram(char *name)
{

    struct stat fileInfo;
    if (stat(name, &fileInfo) == 0 && fileInfo.st_mode & S_IXUSR)
        return 1;
    else
        return 0;
}

//Retourne le chemin vers le dossier contenant les processus pour le mode processus
void setProcessPath(char *callCommand)
{
    char *temp = malloc(sizeof(char) * 256);
    getcwd(temp, 256);
    if (callCommand[0] == '.')
    {
        unsigned int lastSlash = strlen(callCommand);
        for (unsigned int i = 2; i < strlen(callCommand); i++)
        {
            if (callCommand[i] == '/')
                lastSlash = i;
        }
        char *endOFpath = malloc(sizeof(char) * strlen(callCommand));
        for (unsigned int i = 2; i < lastSlash; i++)
            endOFpath[i - 2] = callCommand[i];
        endOFpath[strlen(callCommand) - 1] = '\n';
        strcat(temp, "/");
        strcat(temp, endOFpath);
    }
    strcat(temp, "/processus/");
    processPath = temp;
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
