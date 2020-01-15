/* This is a test of the special shutdown that occurs
   when all threads, including the main one, call
   pthread_exit(). It demonstrates that atexit
   handlers are properly called, and that the
   output is properly flushed even when stdout is
   redirected to a file, and therefore fully buffered. */
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define NTHREADS 20		/* number of threads */

static void *
thread (void *arg)
{
  pid_t tid = (pid_t)syscall(SYS_gettid);
  int i = *((int*)arg);
  printf ("%d thread terminating, TID:%d \n", i, (int)tid);
  return 0;
}

static void
cleanup (void)
{
  printf ("atexit handler called\n");
}

int
main (void)
{
  int i;

  atexit (cleanup);

  int mas[NTHREADS];
  for (i = 0; i < NTHREADS; i++)
  {
      mas[i] = i;
      pthread_t id;
      if (pthread_create (&id, 0, thread, &mas[i]) != 0)
	   {
	      fprintf (stderr, "pthread_create failed\n");
	      abort ();
	   }
  }

  pthread_exit (0);
}
