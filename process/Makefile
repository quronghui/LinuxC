# system process
CC = gcc
CFLAGS = -Wall -g -O

all: fork exec upper pipe

fork: fork.o 
	$(CC) $^ -o $@
fork.o: fork.c 
	$(CC) $(CFLAGS) -c $< -o $@

exec: exec.o 
	$(CC) $^ -o $@
exec.o: exec.c
	$(CC) $(CFLAGS) -c $< -o $@

upper: upper.o 
	$(CC) $^ -o $@
upper.o: upper.c
	$(CC) $(CFLAGS) -c $< -o $@

pipe: pipe.o 
	$(CC) $^ -o $@
pipe.o: pipe.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm fork exec upper pipe
	-rm  *.o 
	@echo "cleanning compile"
.PHONY: clean