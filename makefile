
EXEC=./bin/temp.exe
objectDir = ./bin/object/
Interpreteur = ./interpreteur/
Commande = ./commandes/

SRC= $(wildcard $(Interpreteur)*.c)
OBJ= $(objectDir)main.o $(objectDir)queue.o $(objectDir)linkedList.o $(objectDir)commandParser.o $(objectDir)commandManager.o $(objectDir)commandEntry.o $(objectDir)command.o

all: $(EXEC)


$(EXEC):  $(objectDir)main.o $(OBJ) $(objectDir)ls.o $(objectDir)cat.o $(objectDir)echo.o $(objectDir)rm.o $(objectDir)pwd.o $(objectDir)cp.o $(objectDir)comCommunication.o $(objectDir)interCommunication.o
	gcc -o $(EXEC) $^


#Interpreteur
$(objectDir)main.o: main.c
	gcc -o $@ -c $< -W -Wall
$(objectDir)queue.o:  $(Interpreteur)queue.c 
	gcc -o $@ -c $< -W -Wall
$(objectDir)linkedList.o:  $(Interpreteur)linkedList.c
	gcc -o $@ -c $< -W -Wall
$(objectDir)commandParser.o:  $(Interpreteur)commandParser.c
	gcc -o $@ -c $< -W -Wall
$(objectDir)commandManager.o:  $(Interpreteur)commandManager.c 
	gcc -o $@ -c $< -W -Wall
$(objectDir)commandEntry.o:  $(Interpreteur)commandEntry.c
	gcc -o $@ -c $< -W -Wall


$(objectDir)interCommunication.o:  $(Interpreteur)interCommunication.c
	gcc -o $@ -c $< -W -Wall

#Commandes
$(objectDir)comCommunication.o:  $(Commande)comCommunication.c
	gcc -o $@ -c $< -W -Wall

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
	

$(objectDir)command.o:  $(Interpreteur)command.c
	gcc -o $@ -c $< -W -Wall



clean:
	rm -rf $(objectDir)*.o

mrproper: clean
	rm -rf $(EXEC)