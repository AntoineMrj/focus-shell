
#include "commandParser.h"

//Initialise un parser
void setParser(commandParser *parser, char *chaine)
{
    commandParser *temp = malloc(sizeof(commandParser));
    temp->actualPosition = 0;
    temp->chaine = chaine;
    temp->state = WAIT;
}

//Lit une commande d'un parser
//renvoit 1 quand une commande est parser
//0 quand il n'y plus de commande à parser
//Stocke les commandes trouvé dans cmd
char getActualChar(commandParser *parser)
{
    return parser->chaine[parser->actualPosition];
}
int parse(commandParser *parser, command *cmd)
{
    char buffer[255];
    int bufferPosition = 0;
    int position = parser->actualPosition;
    //Variable temporaire de la commande
    char *argBUFFER[255];
    int actualArg = 0;
    char cmdName[255];
    MODE mode;
    //caractère actuel
    char actualChar = getActualChar(parser);
    if (actualChar == '\0')
    {
        return 0;
    }
    do
    {
        if (actualChar != ' ')
        {
            if (parser->state == WAIT)
            {
                parser->state = PARSING;
            }
        }
        else
        {
            parser->state = WAIT;
            buffer[bufferPosition] = '\0';
            //TEST TYPE
            mode = findMODE(buffer);
            if (mode != NONE)
            {
                break;
            }
            else
            {
                if (actualArg == 0)
                {
                    strcpy(cmdName, buffer);
                }
                else
                {
                    argBUFFER[actualArg] = malloc(sizeof(char) * 256);
                    strcpy(argBUFFER[actualArg], buffer);
                }
                actualArg++;
            }
            buffer[0] = '\0';
            bufferPosition = 0;
        }
        if (parser->state == PARSING)
        {
            buffer[bufferPosition] = actualChar;
            bufferPosition++;
        }
        char actualChar = getActualChar(parser);
        if (actualChar == '\0')
        {
            mode = NONE;
        }
        position++;
    } while (actualChar != '\0');
    parser->actualPosition = position;
    (*cmd) = initCommand(cmdName, actualArg--, argBUFFER, mode);
    return 1;
    //Parse la chaine associé au parser
    //Une fois un symbole de fin de commande trouvé ('<','|','&','&&',...) ou qu'on atteint la fin de la chaine
    //Création initialisation de cmd avec les arguments trouvé
    //retourne 1 si la chaine n'est pas encore vide ou vient juste d'être vidé
    //0 sinon
}
