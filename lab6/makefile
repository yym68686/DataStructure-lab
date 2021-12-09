CC = g++
OUT = a.exe
TARGET =
OBJ = 1Graph.o $(TARGET).o
IN = 1Graph.cpp $(TARGET).cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)