TARGET=test1 test2 test3 test4
CC=gcc
CFLAGS=-Wall

SRC=test1.c test2.c test3.c test4

GMP_INCLUDE=-I/Users/quyennguyen/Programs/libs/gmp/6.2.1/include
GMP_LIBS=-L/Users/quyennguyen/Programs/libs/gmp/6.2.1/lib -lgmp
FLINT_INCLUDE=-I/usr/local/Cellar/flint/2.7.0/include/flint
FLINT_LIBS=-L/usr/local/Cellar/flint/2.7.0/lib -lflint

all: ${TARGET}

#${TARGET} : ${SRC}
#	${CC} ${CFLAGS} -o ${TARGET} ${SRC} ${FLINT_INCLUDE} ${FLINT_LIBS}

test1 : test1.c
	${CC} ${CFLAGS} -o test1 test1.c ${FLINT_INCLUDE} ${FLINT_LIBS}

test2 : test2.c
	${CC} ${CFLAGS} -o test2 test2.c ${FLINT_INCLUDE} ${FLINT_LIBS}

test3 : test3.c
	${CC} ${CFLAGS} -o test3 test3.c ${FLINT_INCLUDE} ${FLINT_LIBS}

test4 : test4.c
	${CC} ${CFLAGS} -o test4 test4.c ${FLINT_INCLUDE} ${FLINT_LIBS}

clean:
	rm *.exe

