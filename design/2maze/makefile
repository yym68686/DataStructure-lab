CC = g++

OUT1 = MazeGeneration.exe
OBJ1 = MazeGeneration.o

OUT2 = main.exe
OBJ2 = main.o Sequence_Stack.o

IN = main.cpp MazeGeneration.cpp Sequence_Stack.cpp

build: $(OUT1) $(OUT2)

run: $(OUT1) $(OUT2)
	@./$(OUT1);./$(OUT2)

clean:
	@rm -f *.o $(OUT1) $(OUT2)

$(OUT1): $(OBJ1)
	@$(CC) $(OBJ1) -o $(OUT1)

$(OUT2): $(OBJ2)
	@$(CC) $(OBJ2) -o $(OUT2)

$(OBJ): $(IN)
	@$(CC) -c $(IN)