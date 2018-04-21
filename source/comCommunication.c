#include "comCommunication.h"

//Initialisation de la libraire
e_outPutMode getOutPutMode()
{
    e_outPutMode ret = CONSOLE_MODE;
    char *temp_envFile = malloc(sizeof(char) * 1024);
    char *tempPPID = malloc(sizeof(256));
    sprintf(tempPPID, "%i", getppid());
    if ((temp_envFile = getenv("fcsShlOut")) != NULL)
    {
        if (strcmp(temp_envFile, tempPPID) == 0)
        {
            ret = LOGFILE_MODE;
        }
        else
        {
            ret = BASHFILE_MODE;
        }
    }
    return ret;
}
FILE *getStdFile()
{
    char *temp_envFile = malloc(sizeof(char) * 1024);
    e_outPutMode outMode = getOutPutMode();
    FILE *fp;
    temp_envFile = getenv("fcsShlOut");

    if (outMode == LOGFILE_MODE)
    {
        char *logFile = malloc(sizeof(char) * 256);
        sprintf(logFile, "/tmp/%s/log.out", temp_envFile);
        fp = fopen(logFile, "a");
        return fp;
    }
    else if (outMode == BASHFILE_MODE)
    {
        char *stdName = malloc(sizeof(char) * 1024);
        sprintf(stdName, "/tmp/%s/std.out", temp_envFile);
        fp = fopen(stdName, "a");
        return fp;
    }

    return NULL;
}
FILE *getErrFile()
{
    char *temp_envFile = malloc(sizeof(char) * 1024);
    e_outPutMode outMode = getOutPutMode();
    FILE *fp;
    temp_envFile = getenv("fcsShlOut");

    if (outMode == LOGFILE_MODE)
    {
        char *logFile = malloc(sizeof(char) * 256);
        sprintf(logFile, "/tmp/%s/log.out", temp_envFile);
        fp = fopen(logFile, "a");
        return fp;
    }
    else if (outMode == BASHFILE_MODE)
    {
        char *errName = malloc(sizeof(char) * 256);
        sprintf(errName, "/tmp/%s/err.out", temp_envFile);
        fp = fopen(errName, "a");
        return fp;
    }

    return NULL;
}

int print(char *str, ...)
{
    //print vers la console
    FILE *fp;
    va_list args;
    va_start(args, str);
    if ((fp = getStdFile()) == NULL)
    {
        vprintf(str, args);
    }
    //print vers des fichiers
    else
    {
        char *temp = malloc(sizeof(char) * 256);
        vsprintf(temp, str, args);
        fprintf(fp, "%s", temp);
        free(temp);
        fclose(fp);
    }
    va_end(args);

    return 0;
}

int printErr(char *str, ...)
{
    //print vers la console
    FILE *fp;
    va_list args;
    va_start(args, str);
    if ((fp = getErrFile()) == NULL)
    {
        vprintf(str, args);
    }
    //print vers des fichiers
    else
    {
        char *temp = malloc(sizeof(char) * 256);
        vsprintf(temp, str, args);
        fprintf(fp, "%s", temp);
        free(temp);
        fclose(fp);
    }
    va_end(args);

    return 0;
}