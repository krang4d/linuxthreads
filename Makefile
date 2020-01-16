CC=gcc
CFLAGS=-g -O -Wall -D_REENTRANT -pthread
#LIBPTHREAD=../libpthread.a

PROGS=ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex7_1 ex8 ex9 ex10 ex11 ex12 ex13 ex16 ex17 ex18 proxy

all: $(PROGS)

.c:
	$(CC) $(CFLAGS) -o $* $*.c 

$(PROGS):

ex1: ex1.c
	$(CC) $(CFLAGS) -o ex1 ex1.c

ex2: ex2.c
	$(CC) $(CFLAGS) -o ex2 ex2.c

ex3: ex3.c
	$(CC) $(CFLAGS) -o ex3 ex3.c

ex4: ex4.c
	$(CC) $(CFLAGS) -o ex4 ex4.c

ex5: ex5.c
	$(CC) $(CFLAGS) -o ex5 ex5.c

ex6: ex6.c
	$(CC) $(CFLAGS) -o ex6 ex6.c

ex7: ex7.c
	$(CC) $(CFLAGS) -o ex7 ex7.c
ex7_1: ex7_1.c
	$(CC) $(CFLAGS) -o ex7_1 ex7_1.c

ex8: ex8.c
	$(CC) $(CFLAGS) -o ex8 ex8.c

ex9: ex9.c
	$(CC) $(CFLAGS) -o ex9 ex9.c

ex10: ex10.c
	$(CC) $(CFLAGS) -o ex10 ex10.c

ex11: ex11.c
	$(CC) $(CFLAGS) -o ex11 ex11.c

ex12: ex12.c
	$(CC) $(CFLAGS) -o ex12 ex12.c

ex13: ex13.c
	$(CC) $(CFLAGS) -o ex13 ex13.c

ex14: ex14.c
	$(CC) $(CFLAGS) -o ex14 ex14.c

ex15: ex15.c
	$(CC) $(CFLAGS) -o ex15 ex15.c

ex16: ex16.c
	$(CC) $(CFLAGS) -o ex16 ex16.c

ex17: ex17.c
	$(CC) $(CFLAGS) -o ex17 ex17.c

ex18: ex18.c
	$(CC) $(CFLAGS) -o ex18 ex18.c

clean:
	rm -f $(PROGS)
