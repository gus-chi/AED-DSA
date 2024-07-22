BIN = ./bin
INC = ./include
OBJ = ./obj
SRC = ./src
TESTS = ./tests

MODULES = $(SRC)/merge-sort.c
BIN_PROGRAM = $(BIN)/main.x

all:	link

link: $(BIN_PROGRAM)

$(BIN)/%.x: $(SRC)/%.c $(MODULES)
	gcc -g $< $(MODULES) -I $(INC) -o $@ 


run:	$(BIN_PROGRAM)
	$<
debug:	$(BIN_PROGRAM)
	gdb $<
clear:
	rm -f $(BIN)/* $(OBJ)/*
