
EXEC=./bin/temp.exe
objectDir = ./bin/object/
Interpreteur = ./interpreteur/
Commande = ./commandes/

SRC= $(wildcard $(Interpreteur)*.c)
OBJ= $(objectDir)main.o $(objectDir)stack.o $(objectDir)queue.o $(objectDir)linkedList.o $(objectDir)commandParser.o $(objectDir)commandManager.o $(objectDir)commandEntry.o $(objectDir)command.o

all: $(EXEC)

$(EXEC):  $(objectDir)main.o $(OBJ) $(objectDir)ls.o
	gcc -o $(EXEC) $^



$(objectDir)main.o: main.c $(Interpreteur)commandEntry.h

$(objectDir)stack.o:  $(Interpreteur)stack.c $(Interpreteur)command.h
	gcc -o $@ -c $< -W -Wall
$(objectDir)queue.o:  $(Interpreteur)queue.c $(Interpreteur)command.h
	gcc -o $@ -c $< -W -Wall
$(objectDir)linkedList.o:  $(Interpreteur)linkedList.c $(Interpreteur)command.h $(Interpreteur)commandFunction.h 
	gcc -o $@ -c $< -W -Wall
$(objectDir)commandParser.o:  $(Interpreteur)commandParser.c $(Interpreteur)command.h
	gcc -o $@ -c $< -W -Wall
$(objectDir)commandManager.o:  $(Interpreteur)commandManager.c $(Interpreteur)command.h
	gcc -o $@ -c $< -W -Wall
$(objectDir)commandEntry.o:  $(Interpreteur)commandEntry.c $(Interpreteur)commandManager.h
	gcc -o $@ -c $< -W -Wall

$(objectDir)ls.o:  $(Commande)ls/ls.c 
	gcc -o $@ -c $< -W -Wall

$(objectDir)command.o:  $(Interpreteur)command.c $(Interpreteur)linkedList.h $(Interpreteur)commandFunction.h $(Commande)ls/ls.h
	gcc -o $@ -c $< -W -Wall



clean:
	rm -rf $(objectDir)*.o

mrproper: clean
	rm -rf $(EXEC)