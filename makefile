
EXEC=./bin/temp.exe
objectDir = ./bin/object/
Interpreteur = ./Interpreteur/


all: $(EXEC)

$(EXEC): $(objectDir)commandParser.o $(objectDir)command.o $(objectDir)main.o
	gcc -o $(EXEC) $(objectDir)commandParser.o $(objectDir)command.o $(objectDir)main.o

$(objectDir)commandParser.o: Interpreteur/commandParser.c
	gcc -o $(objectDir)commandParser.o -c $(Interpreteur)commandParser.c -W -Wall 

$(objectDir)command.o: $(Interpreteur)command.c
	gcc -o $(objectDir)command.o -c $(Interpreteur)command.c -W -Wall

$(objectDir)main.o: main.c $(Interpreteur)command.h $(Interpreteur)commandParser.h
	gcc -o $(objectDir)main.o -c main.c -W -Wall

clean:
	rm -rf $(objectDir)*.o

mrproper: clean
	rm -rf $(EXEC)