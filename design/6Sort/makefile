CC = g++
SOURCE := NumGeneration.cpp Sort.cpp

build:
	@$(foreach var,$(SOURCE),\
		$(CC) -c $(var); \
		$(CC) $(subst .cpp,.o,$(var)) -o $(subst .cpp,.exe,$(var)); \
		./$(subst .cpp,.exe,$(var));\
	)

clean:
	@rm -f *.o *.exe *Sample