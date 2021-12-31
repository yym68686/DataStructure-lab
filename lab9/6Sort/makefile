CC = g++

OUT1 = NumGeneration.exe
OBJ1 = NumGeneration.o

OUT2 = InsertSort.exe
OBJ2 = InsertSort.o

IN = InsertSort.cpp NumGeneration.cpp

build: $(OUT1) $(OUT2)

run: $(OUT1) $(OUT2)
	@./$(OUT1);./$(OUT2)

clean:
	@rm -f *.o $(OUT1) $(OUT2) *Sample

$(OUT1): $(OBJ1)
	@$(CC) $(OBJ1) -o $(OUT1)

$(OUT2): $(OBJ2)
	@$(CC) $(OBJ2) -o $(OUT2)

$(OBJ): $(IN)
	@$(CC) -c $(IN)