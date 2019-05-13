
# 变量定义
OBJS = main.o
CC = gcc
CFLAGS = -Wall -O -g

# Makefile问价
all: main 
main: main.o
	$(CC) $^ -o $@
main.o:	main.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "cleanning compile"
.PHONY:clean