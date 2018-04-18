#include "comCommunication.h"

//Initialisation de la libraire
e_outPutMode getOutPutMode()
{
    e_outPutMode ret = CONSOLE_MODE;
    char *temp_envFile = malloc(sizeof(char) * 1024);
    if ((temp_envFile = getenv("fcsShlOut")) != NULL)
    {
        if (strcmp(temp_envFile, "") == 0)
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
        char *pid = malloc(sizeof(char) * 256);
        char *logFile = malloc(sizeof(char) * 256);
        sprintf(pid, "%i", getpid());
        sprintf(logFile, "/tmp/%s.out", pid);
        fp = fopen(logFile, "aw");
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
        char *pid = malloc(sizeof(char) * 256);
        char *logFile = malloc(sizeof(char) * 256);
        sprintf(pid, "%i", getpid());
        sprintf(logFile, "/tmp/%s.out", pid);
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