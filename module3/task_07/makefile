CC = gcc
CFLAGS = -g -c

all: program_1 program_2

program_1: program_1.o msgchat.o
	$(CC) program_1.o msgchat.o -o program_1

program_2: program_2.o msgchat.o
	$(CC) program_2.o msgchat.o -o program_2

program_1.o: program_1.c 
	$(CC) $(CFLAGS) program_1.c

program_2.o: program_2.c
	$(CC) $(CFLAGS) program_2.c

msgchat.o: msgchat.c
	$(CC) $(CFLAGS) msgchat.c

clean:
	rm -f *.o program_1 program_2 msg_queue
