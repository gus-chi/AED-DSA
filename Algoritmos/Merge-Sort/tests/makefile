BIN = ./bin
INC = ./include
OBJ = ./obj
SRC = ./src
TESTS = ./tests

DEP = $(OBJ)/list.o
MODULES = $(SRC)/list.c
BIN_PROGRAM = $(BIN)/main.x

all:	link
#all:	compile link

#compile:	$(DEP)

link: $(BIN_PROGRAM)

#$(OBJ)/%.o:	$(SRC)/%.c $(INC)/%.h
#	gcc -c $< -I $(INC) -o $@

$(BIN)/%.x: $(SRC)/%.c $(MODULES)
	gcc -g $< $(MODULES) -I $(INC) -o $@ 

#$(BIN)/%.x: $(SRC)/%.c $(DEP)
#	gcc -g $< $(DEP) -I $(INC) -o $@ 

run:	$(BIN_PROGRAM)
	$<
debug:	$(BIN_PROGRAM)
	gdb $<
clear:
	rm -f $(BIN)/* $(OBJ)/*
