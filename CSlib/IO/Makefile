# 
CC = gcc
CFLAGS = -g -Wall

all: fgetc

fgetc: fgetc.o
	$(CC) $^ -o $@
fgetc.o: fgetc.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm fgetc *.o 
	@echo "cleanning compile"
.PHONY:clean