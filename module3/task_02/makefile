CC = gcc
CFLAGS = -g -c

all: program concat max sum

program: main.o 
	$(CC) main.o -o program

concat: concatination.o
	$(CC) concatination.o -o concat

max: max.o
	$(CC) max.c -o max

sum: sum_arg.o
	$(CC) sum_arg.o -o sum

max.o: max.c
	$(CC) $(CFLAGS) max.c

concatination.o: concatination.c
	$(CC) $(CFLAGS) concatination.c

sum_arg.o: sum_arg.c
	$(CC) $(CFLAGS) sum_arg.c

main.o: main.c
	$(CC) $(CFLAGS) main.c


clean:
	rm -f *.o program concat max sum
