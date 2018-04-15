#include "comCommunication.h"

//Initialisation de la libraire
//name = nom de la commande en cours
void printOpen(const char *name)
{
    char *temp_envFile = malloc(sizeof(char) * 1024);
    char *stdName = malloc(sizeof(char) * 1024);
    char *errName = malloc(sizeof(char) * 1024);
    logFile = NULL;
    outPutFileStd = NULL;
    outPutFileErr = NULL;
    outPutMode = NONE;
    if ((temp_envFile = getenv("fcsShlOut")) != NULL)
    {
        if (strcmp(temp_envFile, "") == 0)
        {
            logFile = malloc(sizeof(char) * (strlen(name) + 6));
            sprintf(logFile, "./%s.out", name);
            outPutFileStd = fopen(logFile, "w");
            outPutFileErr = outPutFileStd;
            outPutMode = LOGFILE;
        }
        else
        {
            strcpy(stdName, temp_envFile);
            strcpy(errName, temp_envFile);
            strcat(stdName, "_std.out");
            strcat(errName, "_err.out");
            outPutFileStd = fopen(stdName, "w");
            outPutFileErr = fopen(errName, "w");
            outPutMode = BASHFILE;
        }
    }
    else
    {

        outPutMode = CONSOLE;
    }
    error = 0;
}
//Fermeture de la librairie
void printClose()
{
    if (outPutMode == BASHFILE || outPutMode == LOGFILE)
    {
        fclose(outPutFileStd);
        fclose(outPutFileErr);
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
            fprintf(outPutFileStd, "%s", temp);
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

int printErr(char *str, ...)
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
            fprintf(outPutFileErr, "%s", temp);
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