procDir=./bin/processus/
libDir=./bin/lib/

EXEC_INT=./bin/focusShell_int
EXEC_PROC=./bin/focusShell_proc
EXEC_LIB=./bin/focusShell_lib

LIB = $(libDir)libCommande.a


objectDir = ./object/
sourceDir = ./source/



OBJ_COMMANDE = $(objectDir)ls.o $(objectDir)cat.o $(objectDir)echo.o $(objectDir)rm.o $(objectDir)pwd.o $(objectDir)cp.o $(objectDir)cd.o $(objectDir)chgrp.o $(objectDir)chown.o $(objectDir)chmod.o $(objectDir)du.o $(objectDir)mv.o  $(objectDir)makedir.o $(objectDir)comCommunication.o


OBJ_BASE =  $(objectDir)queue.o $(objectDir)linkedList.o $(objectDir)commandParser.o $(objectDir)commandManager.o $(objectDir)commandEntry.o $(objectDir)command.o $(objectDir)interCommunication.o

OBJ_INT =  $(objectDir)main.o $(objectDir)commandIncluder.o

OBJ_LIB =  $(objectDir)main.o $(objectDir)commandIncluder.o

OBJ_PROC =  $(objectDir)main.o $(objectDir)commandIncluder_proc.o

PROC = $(procDir)rm $(procDir)cp $(procDir)mkdir $(procDir)ls $(procDir)echo $(procDir)cat $(procDir)pwd $(procDir)chown $(procDir)chgrp $(procDir)chmod $(procDir)du

all: $(EXEC_INT) $(LIB) $(EXEC_LIB) $(EXEC_PROC) $(PROC)


$(EXEC_LIB):  $(OBJ_LIB) $(OBJ_BASE) $(OBJ_COMMANDE) 
	gcc -o $(EXEC_LIB) $^  -ldl -L $(libDir) -lCommande


$(EXEC_PROC):  $(OBJ_PROC) $(OBJ_BASE) $(objectDir)cd.o $(objectDir)comCommunication.o 
	gcc -o $(EXEC_PROC) $^

$(EXEC_INT):  $(OBJ_INT) $(OBJ_BASE) $(OBJ_COMMANDE) 
	gcc -o $(EXEC_INT) $^


$(objectDir)%.o : $(sourceDir)%.c
	gcc -o $@ -c $< -W -Wall

$(LIB) : $(OBJ_COMMANDE)
	ar crv $(LIB) $^

#Commande en mode processus

$(procDir)rm : $(objectDir)comCommunication.o $(objectDir)rm.o $(objectDir)main_rm.o 
	gcc -o $@ $^ -W -Wall

$(procDir)cp : $(objectDir)comCommunication.o $(objectDir)cp.o $(objectDir)main_cp.o 
	gcc -o $@ $^ -W -Wall

$(procDir)echo : $(objectDir)comCommunication.o $(objectDir)echo.o $(objectDir)main_echo.o 
	gcc -o $@ $^ -W -Wall

$(procDir)ls : $(objectDir)comCommunication.o $(objectDir)ls.o $(objectDir)main_ls.o 
	gcc -o $@ $^ -W -Wall

$(procDir)mkdir : $(objectDir)comCommunication.o $(objectDir)makedir.o $(objectDir)main_mkdir.o 
	gcc -o $@ $^ -W -Wall

$(procDir)pwd : $(objectDir)comCommunication.o $(objectDir)pwd.o $(objectDir)main_pwd.o 
	gcc -o $@ $^ -W -Wall

$(procDir)du : $(objectDir)comCommunication.o $(objectDir)du.o $(objectDir)main_du.o 
	gcc -o $@ $^ -W -Wall


$(procDir)chown : $(objectDir)comCommunication.o $(objectDir)chown.o $(objectDir)main_chown.o 
	gcc -o $@ $^ -W -Wall


$(procDir)chgrp : $(objectDir)comCommunication.o $(objectDir)chgrp.o $(objectDir)main_chgrp.o 
	gcc -o $@ $^ -W -Wall

$(procDir)chmod : $(objectDir)comCommunication.o $(objectDir)chmod.o $(objectDir)main_chmod.o 
	gcc -o $@ $^ -W -Wall

$(procDir)cat : $(objectDir)comCommunication.o $(objectDir)cat.o $(objectDir)main_cat.o 
	gcc -o $@ $^ -W -Wall

$(procDir)mv : $(objectDir)comCommunication.o $(objectDir)mv.o $(objectDir)main_mv.o 
	gcc -o $@ $^ -W -Wall


clean:
	rm -rf $(objectDir)*.o
	rm -rf $(procDir)*
	rm -rf $(libDir)*
	rm -rf $(EXEC_INT)
	rm -rf $(EXEC_PROC)
	rm -rf $(EXEC_LIB)
