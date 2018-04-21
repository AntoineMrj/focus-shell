procDir=./processus/
libDir=./lib/

EXEC_INT=./bin/focusShell_int.exe
EXEC_PROC=./bin/focusShell_proc.exe

LIB = $(libDir)libCommande.a


objectDir = ./object/
sourceDir = ./source/



OBJ_COMMANDE = $(objectDir)ls.o $(objectDir)cat.o $(objectDir)echo.o $(objectDir)rm.o $(objectDir)pwd.o $(objectDir)cp.o $(objectDir)cd.o $(objectDir)comCommunication.o 


OBJ_BASE =  $(objectDir)queue.o $(objectDir)linkedList.o $(objectDir)commandParser.o $(objectDir)commandManager.o $(objectDir)commandEntry.o $(objectDir)command.o $(objectDir)interCommunication.o

OBJ_INT =  $(objectDir)main_int.o $(objectDir)commandIncluder.o


all: $(EXEC_INT) $(LIB)


$(EXEC_INT):  $(OBJ_INT) $(OBJ_BASE) $(OBJ_COMMANDE) 
	gcc -o $(EXEC_INT) $^


$(objectDir)%.o : $(sourceDir)%.c
	gcc -o $@ -c $< -W -Wall

$(LIB) : $(OBJ_COMMANDE)
	ar crv $(LIB) $^

clean:
	rm -rf $(objectDir)*.o

mrproper: clean
	rm -rf $(EXEC)