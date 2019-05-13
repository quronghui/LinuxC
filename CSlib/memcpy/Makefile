main: main.o
	gcc $^ -o $@
main.o:	main.c
	gcc -c main.c

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"
.PHONY:clean
