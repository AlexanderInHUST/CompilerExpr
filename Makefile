LEX_FILE	= 	main.l
BISON_FILE	=	main.y

LEX_C_FILE	=	main.yy.c
BISON_C_FILE=	main.tab.c

EXE_FILE	=	compiler

CFLAG		=	-I/usr/local/opt/flex/include -I./ -lfl -ly -std=c11
LFLAG		=	-L/usr/local/opt/bison/lib -L/usr/local/opt/flex/lib

wa:
	flex -o $(LEX_C_FILE) $(LEX_FILE)
	bison -o $(BISON_C_FILE) -d -v $(BISON_FILE)
	gcc $(CFLAG) $(LFLAG) $(LEX_C_FILE) $(BISON_C_FILE) -o $(EXE_FILE)

clean:
	rm -rf $(LEX_C_FILE) $(BISON_C_FILE) $(EXE_FILE)