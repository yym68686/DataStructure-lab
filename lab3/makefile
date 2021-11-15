CC = g++
OUT = a.exe
OBJ = 3Eight_Queens.o Sequence_Stack.o
IN = 3Eight_Queens.cpp Sequence_Stack.cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)