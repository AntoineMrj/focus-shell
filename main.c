//#include "interpreteur/commandEntry.h"
#include "interpreteur/commandParser.h"
#include "interpreteur/command.h"

int main(int argc, char *argv[])
{
    //Lancement de la console et de son affichage
    //return commandLine();
    char * temp = "COMANDE1 arg1 && COMMANDE2 arg1 arg2";
    commandParser* tempParser = setParser(temp);
    command* cmd;
    while(parse(tempParser,&cmd)==1)
    {    
        printCommand(cmd);
    }
}