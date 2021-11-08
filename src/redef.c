// ============================================================================
// Original Author  : Peter Dreisiger
// Date Created     : 12-Mar-2008
//
// Purpose          : A simple example of how macros can be used to 'redefine' 
//                    C language keywords to change their rate of execution 
//                    and, with suitable extensions, to implement variable (at
//                    run-time) rates of execution. This might seem like a 
//                    weird thing to do, on the face of it, but it could be 
//                    used in agent models / frameworks to give more CPU time
//                    to better-performing algorithms / variations (think 
//                    evolutionary computing)
//                     
// Licensing        : Copyright (C) 2008, Peter Dreisiger
// ============================================================================
#include <stdio.h>
#include <unistd.h>

#define __varexec_hook usleep(100000)

#define atom      if ((energy > 0) && (usleep(100000) || 1))

#define if(x)     if(__varexec_hook, (x))
#define else      else __varexec_hook,
#define while(x)  while(__varexec_hook, (x))
#define for(x)    for(x, __varexec_hook)
#define switch(x) switch(__varexec_hook, x)
/*
#undef if
#undef else
#undef while
#undef for
#undef switch
*/


int main(int argc, char **argv) {
  int i = 0;

  while (i < 10) {
    printf(".");
    fflush(stdout);
    i++;
  }
  printf("\n");

  for (i = 0; i < 10; i++) {
    printf(".\n");
  }

  if (i == 11) {
    printf("i == 11\n");
  } else 
    printf("i != 11\n");

  return 0;
}
