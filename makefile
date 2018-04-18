
EXEC=./bin/temp.exe
objectDir = ./bin/object/
Interpreteur = ./interpreteur/
Commande = ./commandes/

SRC= $(wildcard $(Interpreteur)*.c)
OBJ= $(objectDir)main.o $(objectDir)stack.o $(objectDir)queue.o $(objectDir)linkedList.o $(objectDir)commandParser.o $(objectDir)commandManager.o $(objectDir)commandEntry.o $(objectDir)command.o

all: $(EXEC)


$(EXEC):  $(objectDir)main.o $(OBJ) $(objectDir)ls.o $(objectDir)cat.o $(objectDir)echo.o $(objectDir)rm.o $(objectDir)pwd.o $(objectDir)cp.o
	gcc -o $(EXEC) $^


#Interpreteur
$(objectDir)main.o: main.c
	gcc -o $@ -c $< -W -Wall
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

#Commandes
$(objectDir)ls.o:  $(Commande)ls/ls.c 
	gcc -o $@ -c $< -W -Wall

$(objectDir)cat.o:  $(Commande)cat/cat.c 
	gcc -o $@ -c $< -W -Wall

$(objectDir)echo.o:  $(Commande)echo/echo.c 
	gcc -o $@ -c $< -W -Wall

$(objectDir)rm.o:  $(Commande)rm/rm.c 
	gcc -o $@ -c $< -W -Wall

$(objectDir)cp.o:  $(Commande)cp/cp.c 
	gcc -o $@ -c $< -W -Wall

$(objectDir)pwd.o:  $(Commande)pwd/pwd.c 
	gcc -o $@ -c $< -W -Wall
	

$(objectDir)command.o:  $(Interpreteur)command.c $(Interpreteur)linkedList.h $(Interpreteur)commandFunction.h $(Commande)ls/ls.h
	gcc -o $@ -c $< -W -Wall



clean:
	rm -rf $(objectDir)*.o

mrproper: clean
	rm -rf $(EXEC)