CC = g++
OUT = a.exe
# TARGET = 2Nonrecursive
# TARGET = 3delete
TARGET = 4Complete_binary_tree
OBJ = 1BinaryTree.o $(TARGET).o
IN = 1BinaryTree.cpp $(TARGET).cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)