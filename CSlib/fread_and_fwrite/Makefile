# fread and fwrite
CC = gcc
CFLAGS = -g -Wall

all: writer reader

writer: writer.o
	$(CC) $^ -o $@
writer.o: writer.c
	$(CC) $(CFLAGS) -c $< -o $@

reader: reader.o
	$(CC) $^ -o $@
reader.o: reader.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "cleanning project"
	-rm writer *.o
	-rm reader
	@echo "cleanning compile"
.PHONY:clean