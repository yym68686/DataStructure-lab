CC = g++
SOURCE := NumGeneration.cpp Sort.cpp

build:
	@$(foreach var,$(SOURCE),\
		$(CC) $(var) -o $(subst .cpp,.exe,$(var)); \
		./$(subst .cpp,.exe,$(var));\
	)

clean:
	@rm -f *.o *.exe *Sample