CC = g++
OUT = a.exe
OBJ = 1Linked_list_sort.o Linked_list.o
IN = Linked_list.cpp 1Linked_list_sort.cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)