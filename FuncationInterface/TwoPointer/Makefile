main: main.o  para_allocator.o
	gcc $^ -o $@

main.o: main.c para_allocator.h
	gcc -c main.c

para_allocator.o: para_allocator.c para_allocator.h
	gcc -c para_allocator.c

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"
.PHONY:clean
