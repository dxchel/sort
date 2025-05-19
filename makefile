<<<<<<< HEAD
# Makefile for g++ program for structures
=======

# Makefile for g++ program Sort
>>>>>>> 41cb4fe (Initialized repo as this project is too old and not a repo)
#Made by David Xchel

#VARIABLES
CC = g++
<<<<<<< HEAD
OBJECTS = obj/main.o obj/structures.o obj/test_structures.o

debug: CFLAGS = -g -Wall -Wextra
debug: obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o structures.exe

release: CFLAGS = -O3
release: clear obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o structures.exe
=======
CLIBS =  -pthread
OBJECTS = obj/main.o obj/sorter.o

debug: CFLAGS = -g -Wall -Wextra
debug: obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o Sort.exe

release: CFLAGS = -O3
release: clear obj ${OBJECTS}
	${CC} ${CFLAGS} ${CLIBS} ${OBJECTS} -o Sort.exe
>>>>>>> 41cb4fe (Initialized repo as this project is too old and not a repo)
	make clean

obj:
	mkdir obj

<<<<<<< HEAD
${OBJECTS}: obj/%.o: src/%.cpp $(wildcard src/headers/%.hpp)
	${CC} ${CFLAGS} ${CLIBS} -c $< -o $@

clear: clean
	touch structures.exe
	rm -r structures.exe
=======
${OBJECTS}: obj/%.o: src/%.cpp
	${CC} ${CFLAGS} ${CLIBS} -c $< -o $@

clear: clean
	touch Sort.exe
	rm -r Sort.exe
>>>>>>> 41cb4fe (Initialized repo as this project is too old and not a repo)
clean:
	touch obj
	rm -r obj
