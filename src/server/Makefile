CC = gcc
EXE = out/deserver.exe
RM = del
OBJ = bin/cJSON.o bin/Main.o bin/SocketFormat.o

$(EXE) : $(OBJ)
	$(CC) -o $@ $^ -lws2_32

bin/cJSON.o : src/cJSON.c
	$(CC) -o $@ $^

bin/Main.o : src/Main.c
	$(CC) -o $@ -c $^

bin/SocketFormat.o : src/SocketFormat.c
	$(CC) -o $@ -c $^

clean:
	$(RM) out\server.exe bin\*.o