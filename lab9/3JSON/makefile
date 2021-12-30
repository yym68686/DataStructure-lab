CC = g++
OUT = a.exe

TARGET1 = main
TARGET2 = 4Kidbrother

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