TARGET=test
CC=gcc
CFLAGS=-Wall

SRC=main.c

GMP_INCLUDE=-I/Users/quyennguyen/Programs/libs/gmp/6.2.1/include
GMP_LIBS=-L/Users/quyennguyen/Programs/libs/gmp/6.2.1/lib -lgmp
FLINT_INCLUDE=-I/usr/local/Cellar/flint/2.7.0/include/flint
FLINT_LIBS=-L/usr/local/Cellar/flint/2.7.0/lib -lflint

all: ${TARGET}

${TARGET} : ${SRC}
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} ${FLINT_INCLUDE} ${FLINT_LIBS}

clean:
	rm *.exe

