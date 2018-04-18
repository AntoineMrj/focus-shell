#include "interCommunication.h"
char *env[] = {NULL, NULL};
char *envVar = "fcsShlOut";
char *envVarEmpty = "fcsShlOut=";

char *channelEnvVar = NULL;
char *stdFileName = NULL;
char *errFileName = NULL;
//Initialise l'environment de communication du shell
void initEnv()
{
    stdFileName = malloc(sizeof(char) * 256);
    errFileName = malloc(sizeof(char) * 256);
    channelEnvVar = malloc(sizeof(char) * 128);
    char *temp = malloc(sizeof(char) * 32);
    env[0] = (char *)malloc(sizeof(char) * 256);

    char *pid = malloc(sizeof(char) * 256);

    sprintf(pid, "%i", getpid());

    sprintf(stdFileName, "/tmp/%s/std.out", pid);
    sprintf(errFileName, "/tmp/%s/err.out", pid);
    sprintf(temp, "/tmp/%s", pid);
    mkdir(temp, ACCESSPERMS);
    //Initialisation de la variable d'environment
    strcat(channelEnvVar, envVarEmpty);
    strcat(channelEnvVar, pid);
    //Création du fichier de communication
    FILE *channelFile = fopen(stdFileName, "a");
    fclose(channelFile);
    channelFile = fopen(errFileName, "a");
    fclose(channelFile);
}
char **getEnv()
{
    return env;
}
//Choisit le mode de communication des résultats
void setEnvMode(e_envMode mode)
{
    switch (mode)
    {
    case CONSOLE:
        env[0] = NULL;
        break;
    case LOGFILE:
        strcpy(env[0], envVarEmpty);
        break;
    case BASHFILE:
        strcpy(env[0], channelEnvVar);
        break;
    }
    if (env[0] == NULL)
    {
        unsetenv(envVar);
    }
    else
    {
        putenv(env[0]);
    }
}
//Fermeture de l'environment de communication en supprimant le fichier
void closeEnvironment()
{
    remove(stdFileName);
    remove(errFileName);
}
int sizeOfFile(char *file)
{
    int sizeF;
    FILE *channelFile = fopen(file, "r");
    if (channelFile)
    {
        fseek(channelFile, 0L, SEEK_END);
        sizeF = ftell(channelFile);
        rewind(channelFile);
        fclose(channelFile);
    }
    else
    {
        printf("ERROR while reading channelFile, did you initialise the environment ?");
    }
    return sizeF;
}
void readFile(char *file)
{
    char *lineBuffer = (char *)malloc(sizeof(char) * 256);
    FILE *channelFile = fopen(file, "r");
    if (channelFile)
    {
        while ((fgets(lineBuffer, sizeof(lineBuffer), channelFile)))
        {
            printf("%s", lineBuffer);
        }
        fclose(channelFile);
    }
    else
    {
        printf("ERROR while reading channelFile, did you initialise the environment ?");
    }
    free(lineBuffer);
}
char *getFile(char *file)
{
    char *result = NULL;
    char *lineBuffer = (char *)malloc(sizeof(char) * 256);
    FILE *channelFile = fopen(file, "r");
    if (channelFile)
    {
        fseek(channelFile, 0L, SEEK_END);
        int sizeF = ftell(channelFile);
        rewind(channelFile);
        result = calloc(sizeF, sizeof(char));
        while ((fgets(lineBuffer, sizeof(lineBuffer), channelFile)))
        {
            strcat(result, lineBuffer);
        }
        fclose(channelFile);
    }
    else
    {
        printf("ERROR while reading channelFile, did you initialise the environment ?");
    }
    free(lineBuffer);
    return result;
}
//Récupère le contenu du fichier de communication
char *getStd()
{
    return getFile(stdFileName);
}

char *getErr()
{
    return getFile(errFileName);
}
//Récupère le contenu du fichier de communication
void readStd()
{
    readFile(stdFileName);
}

void readErr()
{
    readFile(errFileName);
}
int hasStd()
{
    return sizeOfFile(stdFileName);
}
int hasErr()
{
    return sizeOfFile(errFileName);
}
void flushFile(char *file)
{
    FILE *channelFile = fopen(file, "w");
    fclose(channelFile);
}
void flush()
{
    flushFile(stdFileName);
    flushFile(errFileName);
}