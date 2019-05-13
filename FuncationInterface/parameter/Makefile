main: main.o populator.o
		gcc main.o populator.o -o main
main.o:	main.c populator.h
		gcc -c main.c
populator.o: populator.c populator.h
		gcc -c populator.c

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "cleanning completed"
.PHONY:clean