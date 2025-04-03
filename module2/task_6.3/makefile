CC = gcc

all: my_program

LIB_DIR = operation

my_program: main.o menu.o $(LIB_DIR)/libadd.so $(LIB_DIR)/libsub.so $(LIB_DIR)/libmult.so $(LIB_DIR)/libdiv.so
	$(CC) main.o menu.o -ldl -o my_program

$(LIB_DIR)/libadd.so: $(LIB_DIR)/addition.c
	$(CC) -shared -o $(LIB_DIR)/libadd.so $(LIB_DIR)/addition.c

$(LIB_DIR)/libsub.so: $(LIB_DIR)/subtraction.c
	$(CC) -shared -o $(LIB_DIR)/libsub.so $(LIB_DIR)/subtraction.c

$(LIB_DIR)/libmult.so: $(LIB_DIR)/multiplication.c
	$(CC) -shared -o $(LIB_DIR)/libmult.so $(LIB_DIR)/multiplication.c

$(LIB_DIR)/libdiv.so: $(LIB_DIR)/division.c
	$(CC) -shared -o $(LIB_DIR)/libdiv.so $(LIB_DIR)/division.c

main.o: main.c
	$(CC) -fPIC -c main.c -o main.o

menu.o: menu.c
	$(CC) -fPIC -c menu.c -o menu.o

clean:
	rm -f *.o my_program $(LIB_DIR)/*.so $(LIB_DIR)/*.o 
