NUM = 2
# LIST = Linked_list
LIST = Sequence_list
CC = g++
OUT = a.exe
OBJ = $(NUM)$(LIST)_union.o $(LIST).o
IN = $(NUM)$(LIST)_union.cpp $(LIST).cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)