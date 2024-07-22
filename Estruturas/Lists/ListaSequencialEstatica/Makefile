BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

DEP = $(OBJ)/list.o
PROGRAM_BIN = $(BIN)/main.x

FLAGS = -O3
#-Wall 

all: compile linking

compile: $(DEP)

linking:	$(PROGRAM_BIN)
	
$(BIN)/%.x:	$(SRC)/%.c $(OBJ)/*.o
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

$(OBJ)/%.o:	$(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

run:	$(PROGRAM_BIN)
	$(PROGRAM_BIN)
clear:
	rm -f $(BIN)/* $(OBJ)/*
