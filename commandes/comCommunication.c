#include "comCommunication.h"

//Initialisation de la libraire
//name = nom de la commande en cours
void printOpen(const char *name)
{
    char *temp_envFile = malloc(sizeof(char) * 1024);
    logFile = NULL;
    outPutFile = NULL;
    outPutMode = NONE;
    if ((temp_envFile = getenv("fcsShlOut")) != NULL)
    {
        if (strcmp(temp_envFile, "") == 0)
        {
            logFile = malloc(sizeof(char) * (strlen(name) + 6));
            sprintf(logFile, "./%s.out", name);
            outPutFile = fopen(logFile, "w");
            outPutMode = LOGFILE;
        }
        else
        {
            outPutFile = fopen(temp_envFile, "w");
            outPutMode = BASHFILE;
        }
    }
    else
    {

        outPutMode = CONSOLE;
    }
}
//Fermeture de la librairie
void printClose()
{
    if (outPutMode == BASHFILE || outPutMode == LOGFILE)
    {
        fclose(outPutFile);
    }
}
int print(char *str, ...)
{

    //print vers la console
    if (outPutMode != NONE)
    {
        va_list args;
        va_start(args, str);
        if (outPutMode == CONSOLE)
        {
            vprintf(str, args);
        }
        //print vers des fichiers
        else
        {
            char *temp = malloc(sizeof(char) * 256);
            vsprintf(temp, str, args);
            fprintf(outPutFile, "%s", temp);
            free(temp);
        }
        va_end(args);
    }
    else
    {
        printf("Print output is not defined, have you initialise print with \"printOpen()\" ?");
    }

    return 0;
}