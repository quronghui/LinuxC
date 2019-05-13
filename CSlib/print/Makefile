# 
CC = gcc
CFLAGS = -g -Wall

all: main print

main: main.o
	$(CC) $^ -o $@
main.o: main.c 
	$(CC) $(CFLAGS) -c $< -o $@

print: print.o
	$(CC) $^ -o $@
print.o: print.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm main *.o 
	 -rm print
	@echo "cleanning compile"
.PHONY:clean