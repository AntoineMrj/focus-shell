#include "commandManager.h"

//Envoit la chaine de caractère à un parser pour l'analyser
void analyse(char *argv)
{
    //Lancement de la console et de son affichage
    //return commandLine();
    int returnHandler = 0;
    commandParser *tempParser = setParser(argv);
    command *cmd = NULL;
    commandQueue *cmdQueue = initQueue();
    while ((returnHandler = parse(tempParser, &cmd)) == 1)
    {
        pushQ(cmdQueue, cmd);
        cmd = NULL;
    }
    executeQueue(cmdQueue, 1, 1);
    if (returnHandler == 2)
    {
        printf("ERREUR LORS DU PARSING DE LA COMMANDE\n");
    }

    //Vérification de l'erreur
}
void executeQueue(commandQueue *cmdQueue, int hasToFlush, int readOut)
{
    int tempReadout;
    int tempFlush;
    while (getTopQ(cmdQueue) != NULL)
    {
        command cmd = popQ(cmdQueue);
        command *temp;
        command file;
        command *cmd_ptr;
        tempReadout = readOut;
        tempFlush = hasToFlush;
        pid_t pid;
        switch (cmd.mode)
        {
        case NONE:
            executeCommand(&cmd);
            break;
        case REDIRECT_OUT:
            file = popQ(cmdQueue);
            executeCommandToFile(&cmd, file.name, "a");
            tempReadout = 0;
            if (file.mode == AND)
            {
                if (hasErr() > 0)
                    popQ(cmdQueue);
            }
            else if (file.mode == OR)
            {
                if (hasErr() == 0)
                    popQ(cmdQueue);
            }
            break;
        case REDIRECT_OUT_END:
            file = popQ(cmdQueue);
            executeCommandToFile(&cmd, file.name, "a");
            tempReadout = 0;
            if (file.mode == AND)
            {
                if (hasErr() > 0)
                    popQ(cmdQueue);
            }
            else if (file.mode == OR)
            {
                if (hasErr() == 0)
                    popQ(cmdQueue);
            }
            break;
        case PIPE:
            executeCommand(&cmd);
            commandParser *tempParser = setParser(getStd());
            temp = getTopQ(cmdQueue);
            parse(tempParser, &temp);
            setTopQ(cmdQueue, temp);
            tempReadout = 0;
            break;
        case AND:
            executeCommand(&cmd);
            if (hasErr() >= 0)
                popQ(cmdQueue);
            break;
        case OR:
            executeCommand(&cmd);
            if (hasErr() == 0)
                popQ(cmdQueue);
            break;
        case REDIRECT_IN:
            file = popQ(cmdQueue);
            cmd_ptr = &cmd;
            tempParser = setParser(getFile(file.name));
            parse(tempParser, &(cmd_ptr));
            cmd.mode = file.mode;
            pushEndQ(cmdQueue, cmd_ptr);
            break;
        case REDIRECT_ENTRY:
            file = popQ(cmdQueue);
            cmd_ptr = &cmd;
            tempParser = setParser(getUserEntry(file.name));
            parse(tempParser, &(cmd_ptr));
            cmd.mode = file.mode;
            pushEndQ(cmdQueue, cmd_ptr);
            break;
        case DETACHEMENT:
            pid = fork();
            if (pid == 0)
            {
                executeCommand(&cmd);
                exit(0);
            }
            else
            {
                printf("[] %i\n", pid);
            }
            break;
        default:
            executeCommand(&cmd);
            break;
        }
        if (tempReadout)
        {
            readStd();
        }
        if (tempFlush)
        {
            flush();
        }
    }
    if (hasLog() > 0)
    {
        readLog();
        flushLog();
    }
}

char *getUserEntry(char *endString)
{
    const size_t entrySize = 128;
    char *entry = malloc(sizeof(char) * entrySize); //Commande de l'utilsateur
    char *out = calloc(1, sizeof(char));
    //Retour de l'analyse
    //Nettoyage du terminal
    //Tant que l'utilisateur ne quitte pas le terminal
    printf("\n");
    do
    {
        //Code de gestion de l'affichage du terminal
        printf(">");
        fgets(entry, entrySize, stdin);
        entry[strlen(entry) - 1] = '\0';
        if (strcmp(entry, endString) != 0)
        {
            entry[strlen(entry)] = '\n';
            out = realloc(out, strlen(out) + strlen(entry));
            strcat(out, entry);
        }

    } while (strcmp(entry, endString) != 0);
    return out;
}