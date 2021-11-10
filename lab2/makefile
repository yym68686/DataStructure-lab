# NUM = 1
# NUM = 2
NUM = 3

LIST = Linked_list
# LIST = Sequence_list

# OP = sort
# OP = union
OP = Josephus

CC = g++
OUT = a.exe
OBJ = $(NUM)$(LIST)_$(OP).o $(LIST).o
IN = $(NUM)$(LIST)_$(OP).cpp $(LIST).cpp

build: $(OUT)

run: $(OUT)
	@./$(OUT)

clean:
	@rm -f *.o $(OUT)

$(OUT): $(OBJ)
	@$(CC) $(OBJ)

$(OBJ): $(IN)
	@$(CC) -c $(IN)