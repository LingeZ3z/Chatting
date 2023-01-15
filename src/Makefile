CC = gcc
RM = del
SERVOBJ = bin/cJSON.o bin/ServerMain.o bin/SocketFormat.o
CLNTOBJ = bin/CilentMain bin/SocketFormat.o

server : $(SERVOBJ)
	$(CC) -o $@ $^ -lws2_32

cilent : $(SERVOBJ)
	$(CC) -o $@ $^ -lws2_32

bin/cJSON.o : src/cJSON.c
	$(CC) -o $@ -c $^

bin/Main.o : src/Main.c
	$(CC) -o $@ -c $^

bin/SocketFormat.o : src/SocketFormat.c
	$(CC) -o $@ -c $^

bin/CilentMain : src/CilentMain.c
	$(CC) -o $@ -c $^


clean:
	$(RM) out\server.exe bin\*.o