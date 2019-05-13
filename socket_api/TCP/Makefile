# complie condition
CC = gcc
CFLAGS = -g -Wall 

# binary file
all: server client client_interactive

server: server.o wrap.o
	$(CC) $^ -o $@
server.o: server.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@
wrap.o: wrap.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@

client: client.o
	$(CC) $^ -o $@
client.o: client.c
	$(CC) $(CFLAGS) -c $< -o $@


client_interactive: client_interactive.o wrap.o		# 依赖文件wrap也要编译成wrap.o库文件；而不是编译成可执行文件
	$(CC) $^ -o $@
client_interactive.o: client_interactive.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@
wrap.o: wrap.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm server client client_interactive
	-rm *.o
	@echo "cleanning complie"
.PHONY:clean