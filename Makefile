ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: parse_main.o
	$(CC) -o parse parse_main.o

parse_main.o: parse_main.c
	$(CC) -c parse_main.c

run:
	./parse

memcheck:
	valgrind --leak-check=yes ./parse

clean:
	rm *.o
	rm *~
