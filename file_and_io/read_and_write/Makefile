# read and write 

CC = gcc
CFLAGS = -Wall -O -g

all: unblock

unblock: unblock.o
	$(CC) $^ -o $@
unblock.o:	Unblocking_read_terminal.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm unblock *.o
	@echo "cleanning compile"
.PHONY:clean	 