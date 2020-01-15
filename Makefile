CC=gcc
CFLAGS=-g -O -Wall -D_REENTRANT -pthread
#LIBPTHREAD=../libpthread.a

PROGS=ex1 ex2 ex3 ex4 ex5 ex5 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex16 ex17 ex18 proxy

all: $(PROGS)

.c:
	$(CC) $(CFLAGS) -o $* $*.c $(LIBPTHREAD)

$(PROGS):

clean:
	rm -f $(PROGS)
