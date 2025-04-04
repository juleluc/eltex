CC = gcc
CFLAGS = -g -c

all: my_program

my_program: main.o generate_ip.o check_subnet.o 
	$(CC) main.o generate_ip.o check_subnet.o -o my_program

main.o: main.c
	$(CC) $(CFLAGS) main.c

generate_ip.o: generate_ip.c
	$(CC) $(CFLAGS) generate_ip.c

check_subnet.o: check_subnet.c
	$(CC) $(CFLAGS) check_subnet.c
clean:
	rm -f *.o my_program test
