#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
bye(void)
{
   printf("That was all, folks\n");
}

void
bye2(void)
{
   printf("That was all, folks2\n");
}

int
main(void)
{
   long a;
   int i;

   a = sysconf(_SC_ATEXIT_MAX);
   printf("ATEXIT_MAX = %ld\n", a);

   i = atexit(bye);
   i = atexit(bye2);
   if (i != 0) {
      fprintf(stderr, "cannot set exit function\n");
      exit(EXIT_FAILURE);
   }

   exit(EXIT_SUCCESS);
}
