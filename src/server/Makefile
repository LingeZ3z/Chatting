CC = gcc
EXE = server
RM = rm
OBJ = bin/cJSON.o bin/Main.o bin/SocketFormat.o

$(EXE) : $(OBJ)
	@echo 6
	$(CC) -o $@ $^

bin/cJSON.o : src/cJSON.c
	$(CC) -o $@ $^

bin/Main.o : src/Main.c
	$(CC) -o $@ -c $^

bin/SocketFormat.o : src/SocketFormat.c
	$(CC) -o $@ -c $^

clean:
	$(RM) $(EXE) $(OBJ)