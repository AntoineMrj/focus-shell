#include "interCommunication.h"

char *env[] = {NULL, NULL};
char *envVar = "fcsShlOut";
char *envVarEmpty = "fcsShlOut=";

char *channelEnvVar = NULL;
char *channelFileName = NULL;
char *outFileName = NULL;

char *cutDirectory(char *command)
{
    int i = 0;
    int buffPosition = 0;
    char *buff = malloc(sizeof(char) * 50);
    char *out = malloc(sizeof(char) * 50);
    if (command[0] == '/')
        buff[buffPosition++] = command[i];
    while ((command[i++]) != '\0')
    {
        buff[buffPosition++] = command[i];
        if (command[i] == '/')
            strcpy(out, buff);
    }
    return out;
}

//Initialise l'environment de communication du shell
void initEnv(char *command)
{
    outFileName = malloc(sizeof(char) * 256);
    channelEnvVar = malloc(sizeof(char) * 128);
    channelFileName = malloc(sizeof(char) * 256);
    env[0] = (char *)malloc(sizeof(char) * 256);
    size_t size = 256;

    //Initialisation du nom du fichier de communication avec le pid du shell
    if (command[0] == '.')
    {
        getcwd(channelFileName, size);
    }
    strcat(channelFileName, cutDirectory(command));
    strcat(channelFileName, "/channel/");
    sprintf(outFileName, "%i.out", getpid());
    strcat(channelFileName, outFileName);
    //Initialisation de la variable d'environment
    strcat(channelEnvVar, envVar);
    strcat(channelEnvVar, "=");
    strcat(channelEnvVar, channelFileName);

    //Création du fichier de communication
    FILE *channelFile = fopen(channelFileName, "a");
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
    remove(channelFileName);
}
//Récupère le contenu du fichier de communication
char *readCommunication()
{
    char *result = NULL;
    char *lineBuffer = (char *)malloc(sizeof(char) * 256);
    off_t sizeOfFile;
    FILE *channelFile = fopen(channelFileName, "r");

    if (channelFile)
    {
        sizeOfFile = ftello(channelFile);
        fseek(channelFile, 0, SEEK_SET);

        result = (char *)malloc(sizeof(char) * sizeOfFile);

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
    // free(lineBuffer);
    return result;
}