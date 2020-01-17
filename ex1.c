/* Creates two threads, one printing 10000 "a"s, the other printing
   10000 "b"s.
   Illustrates: thread creation, thread joining. */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "pthread.h"

#define _GNU_SOURCE         /*  See feature_test_macros(7) */
#include <unistd.h>
#include <sys/syscall.h>   /*  For SYS_xxx definitions */

static void *
process (void *arg)
{
  int i;
  pid_t tid;
  tid = syscall(SYS_gettid);

  fprintf (stderr, "Starting process %s\n", (char *) arg);
  for (i = 0; i < 10; i++)
    {
      printf("ID: %ld TID: %ld\n", pthread_self(), tid);
      write (1, (char *) arg, 1);
      printf(" \n");
      sleep(1);
    }
  return NULL;
}

int
main (void)
{

   
  int retcode;
  pthread_t th_a, th_b;
  void *retval;

  retcode = pthread_create (&th_a, NULL, process, (void *) "a");
  if (retcode != 0)
    fprintf (stderr, "create a failed %d\n", retcode);
  retcode = pthread_create (&th_b, NULL, process, (void *) "b");
  if (retcode != 0)
    fprintf (stderr, "create b failed %d\n", retcode);
  retcode = pthread_join (th_a, &retval);
  if (retcode != 0)
    fprintf (stderr, "join a failed %d\n", retcode);
  retcode = pthread_join (th_b, &retval);
  if (retcode != 0)
    fprintf (stderr, "join b failed %d\n", retcode);
  return 0;
}
