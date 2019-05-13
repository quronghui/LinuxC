main: main.o ret_ptr.o
	gcc $^ -o $@
main.o: main.c ret_ptr.h
	gcc -c main.c
ret_ptr.o: ret_ptr.c ret_ptr.h
	gcc -c ret_ptr.c

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"