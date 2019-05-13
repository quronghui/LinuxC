# Pthread
CC = gcc
CFLAGS = -g -Wall 
CTHREAD = -lpthread		# -lprhread 在pthread_create.o 文件后链接线程库

# all
all:	pthread_create pthread_exit pthread_metux pthread_con semaphore

pthread_create:	pthread_create.o
	$(CC) $^ $(CTHREAD) -o  $@ 		
pthread_create.o:	pthread_create.c
	$(CC) $(CFLAGS) -c $< -o $@ 

pthread_exit:	pthread_exit.o
	$(CC) $^ $(CTHREAD) -o  $@ 		
pthread_exit.o:	pthread_exit.c
	$(CC) $(CFLAGS) -c $< -o $@ 

pthread_metux:	pthread_metux.o
	$(CC) $^ $(CTHREAD) -o  $@ 		
pthread_metux.o:	pthread_metux.c
	$(CC) $(CFLAGS) -c $< -o $@ 

pthread_con:	pthread_con.o
	$(CC) $^ $(CTHREAD) -o  $@ 		
pthread_con.o:	pthread_con.c
	$(CC) $(CFLAGS) -c $< -o $@ 

semaphore:	semaphore.o
	$(CC) $^ $(CTHREAD) -o  $@ 		
semaphore.o:	semaphore.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@echo "cleaning project"
	-rm pthread_create pthread_exit 
	-rm	pthread_metux pthread_con
	-rm	semaphore
	-rm *.o
	@echo "cleaning compling"
.PHONY:	clean