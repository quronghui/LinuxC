# complie condition
CC = gcc
CFLAGS = -g -Wall 

#all
all: client server

client:	client.o wrap.o
	$(CC) $^ -o $@
client.o: client.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@
wrap.o:	wrap.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@

server:	server.o wrap.o
	$(CC) $^ -o $@
server.o: server.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@
wrap.o:	wrap.c wrap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm server client 
	-rm *.o
	@echo "cleanning complie"
.PHONY:clean
