CC = gcc
CFLAGS = -g -c

all: server client sniffer

server: server.o common.o
	$(CC) server.o common.o -o server

client: client.o common.o
	$(CC) client.o common.o -o client

sniffer: sniffer.o
	$(CC) sniffer.c -o sniffer

sniffer.o: sniffer.c
	$(CC) $(CFLAGS) sniffer.c

server.o: server.c 
	$(CC) $(CFLAGS) server.c

client.o: client.c
	$(CC) $(CFLAGS) client.c

common.o: common.c
	$(CC) $(CFLAGS) common.c

clean:
	rm -f *.o server client sniffer
