CFLAGS := -std=c11 -Werror -Wall -Wextra -Wpedantic
CC := gcc

run: bin/main
	bin/./main

bin/main: obj/node.o src/main.c
	$(CC) $(CFLAGS) src/main.c obj/node.o -o bin/main

obj/node.o: src/node.c src/node.h
	$(CC) $(CFLAGS) -c src/node.c -o obj/node.o

clean:
	rm obj/*
	rm bin/*
