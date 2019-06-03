# complie condition
CC = gcc
CFLAGS = -g -Wall 

#all
all: bind

bind:	bind.o
	$(CC) $^ -o $@
bind.o:	bind.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm bind
	-rm *.o
	@echo "cleanning complie"
.PHONY:clean