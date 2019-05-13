# fcntl 实现非阻塞

# parameter setting
CC = gcc
CFLAGS = -Wall -g -O

# Makefile
all: file_status_flag cmd_flag

file_status_flag: file_status_flag.o
	$(CC) $^ -o $@
file_status_flag.o: file_status_flag.c
	$(CC) $(CFLAGS) -c $< -o $@

cmd_flag: cmd_flag.o
	$(CC) $^ -o $@
cmd_flag.o: cmd_flag.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm file_status_flag *.o 
	-rm cmd_flag
	@echo "cleanning compile"
.PHONY:clean