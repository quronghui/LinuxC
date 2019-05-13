main: main.o para_callback.o
	gcc $^ -o $@
main.o: main.c para_callback.h
	gcc -c main.c
para_callback.o: para_callback.c para_callback.h
	gcc -c para_callback.c

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"
.PHONY:clean