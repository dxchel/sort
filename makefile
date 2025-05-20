# Makefile for g++ program Sort
#Made by David Xchel

#VARIABLES
CC = g++
CLIBS =  -pthread
OBJECTS = obj/main.o obj/sorter.o

debug: CFLAGS = -g -Wall -Wextra
debug: obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o Sort.exe

release: CFLAGS = -O3
release: clear obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o Sort.exe
	make clean

obj:
	mkdir obj

${OBJECTS}: obj/%.o: src/%.cpp
	${CC} ${CFLAGS} ${CLIBS} -c $< -o $@

clear: clean
	touch Sort.exe
	rm -r Sort.exe
clean:
	touch obj
	rm -r obj
