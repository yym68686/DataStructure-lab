CC = g++
OUT = a.exe

TARGET1 = 4Outputelement
TARGET2 = 4Kidbrother

# TARGET1 = 3BinaryTreeweigh
# TARGET2 = 3BinaryTree

# TARGET2 = 1Graph
OBJ = $(TARGET2).o $(TARGET1).o
IN = $(TARGET2).cpp $(TARGET1).cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)