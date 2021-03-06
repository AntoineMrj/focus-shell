
#include "commandParser.h"

//Initialise un parser
commandParser *setParser(char *chaine)
{
    commandParser *temp = malloc(sizeof(commandParser));
    temp->actualPosition = 0;
    normaliseStr(chaine);
    temp->chaine = chaine;
    temp->hasEnded = 0;
    return temp;
}

//Lit une commande d'un parser
//renvoit 1 quand une commande est parsée
//0 quand il n'y plus de commande à parser
//Stocke les commandes trouvées dans cmd
char getActualChar(commandParser *parser)
{
    char temp = parser->chaine[parser->actualPosition];
    parser->actualPosition++;
    return temp;
}

int parse(commandParser *parser, command **cmd)
{
    //Sortie si on a déjà atteint la fin dans un appel précédent
    if (parser->hasEnded == 1)
        return 0;
    //Création du buffer
    char *buffer = malloc(sizeof(char) * 255);
    int bufferPosition = 0;
    //Variable temporaire de la commande
    char *argBUFFER[255];
    char *cmdName = malloc(sizeof(char) * 255);
    int actualArg = 0;
    if (*cmd != NULL)
    {
        actualArg = (*cmd)->nbArg;
        for (int i = 0; i < (*cmd)->nbArg; i++)
        {
            argBUFFER[i] = (*cmd)->arg[i];
        }
        if ((*cmd)->nbArg >= 1)
            cmdName = (*cmd)->name;
    }
    MODE mode;
    //Variable de parcours de la chaîne
    char actualChar = 'X';
    while (actualChar != '\0')
    {
        //Ignore les espaces
        while ((actualChar = getActualChar(parser)) == ' ')
            ;
        //Initialisation du buffer
        buffer[0] = '\0';
        bufferPosition = 0;
        do
        {
            if (actualChar == '\0')
            {
                parser->hasEnded = 1;
                break;
            }
            buffer[bufferPosition] = actualChar;
            bufferPosition++;
        } while ((actualChar = getActualChar(parser)) != ' ');
        //Marque la fin du buffer
        buffer[bufferPosition] = '\0';
        //Récupération du mode
        mode = findMODE(buffer);
        //Si la chaîne ne correspond pas à un mode et quelle n'est pas vide
        if (mode == NONE && bufferPosition > 0 && buffer[0] != '\0')
        {
            //Assignation de la première chaîne au nom de la commande
            if (actualArg == 0)
            {
                strcpy(cmdName, buffer);
            }
            argBUFFER[actualArg] = malloc(sizeof(char) * 255);
            strcpy(argBUFFER[actualArg], buffer);
            actualArg++;
        }
        else
        {
            break;
        }
    }
    if (actualArg > 0)
    {
        //Copie de la commande créée
        (*cmd) = initCommand(cmdName, actualArg, argBUFFER, mode);
        return 1;
    }
    else
    {
        //ERREUR
        return 0;
    }
    return 2;
}

//Ajoute un \0 à la fin de la chaîne pour la "normaliser"
void normaliseStr(char *chaine)
{
    chaine[strlen(chaine) - 1] = '\0';
}
