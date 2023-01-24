CC = gcc
CFLAGS = -I${SDLINC} -I${IDIR} -L${SDLLIB} -Wall -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

IDIR = ./include/
SRCDIR = ./src/

SOURCES = ${SRCDIR}*.c

SDLINC = ./SDL2/include/SDL2
SDLLIB = ./SDL2/lib/

all:	build

build:	${SOURCES}
	${CC} ${SOURCES} ${CFLAGS} -o main

debug: ${SOURCES}
	${CC} -g -Wextra ${SOURCES} ${CFLAGS} -o main

run:
	./main

clean:
	del main.exe