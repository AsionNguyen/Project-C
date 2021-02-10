CC=gcc
CFLAGS=-Wall

GMP_INCLUDE=-I/Users/quyennguyen/Programs/libs/gmp/6.2.1/include
GMP_LIBS=-L/Users/quyennguyen/Programs/libs/gmp/6.2.1/lib -lgmp
FLINT_INCLUDE=-I/usr/local/Cellar/flint/2.7.0/include/flint
FLINT_LIBS=-L/usr/local/Cellar/flint/2.7.0/lib -lflint

test7 : test7.c
	${CC} ${CFLAGS} -o test7 test7.c ${FLINT_INCLUDE} ${FLINT_LIBS}

clean:
	rm *.exe

