
#include "commandParser.h"

//Initialise un parser
commandParser *setParser(char *chaine)
{
    commandParser *temp = malloc(sizeof(commandParser));
    temp->actualPosition = 0;
    temp->chaine = chaine;
    temp->state = WAIT;
    temp->hasEnded = 0;
    return temp;
}

//Lit une commande d'un parser
//renvoit 1 quand une commande est parser
//0 quand il n'y plus de commande à parser
//Stocke les commandes trouvé dans cmd
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
    char buffer[255];
    int bufferPosition = 0;
    //Variable temporaire de la commande
    char *argBUFFER[255];
    int actualArg = 0;
    char cmdName[255];
    MODE mode;
    //Variable de parcours de la chaine
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
        //Si la chaine ne correspond pas à un mode et quelle n'est pas vide
        if (mode == NONE && bufferPosition > 0)
        {
            //Assignation de la première chaine au nom de la commande
            if (actualArg == 0)
            {
                strcpy(cmdName, buffer);
            }
            //Le reste à ses arguments
            else
            {
                argBUFFER[actualArg - 1] = malloc(sizeof(char) * 256);
                strcpy(argBUFFER[actualArg - 1], buffer);
            }
            actualArg++;
        }
        else
        {
            break;
        }
    }
    if (actualArg > 0)
    {
        //Copie de la commande crée
        (*cmd) = initCommand(cmdName, actualArg - 1, argBUFFER, mode);
    }
    else
    {
        //ERREUR
        return 2;
    }
    return 1;
}
