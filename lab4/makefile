CC = g++
OUT = a.exe
OBJ = 1BinaryTree.o 3delete.o
IN = 1BinaryTree.cpp 3delete.cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)