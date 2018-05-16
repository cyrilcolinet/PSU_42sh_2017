/*
** EPITECH PROJECT, 2018
** foo
** File description:
** oui
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

int main (void)
{
	pid_t pid;
	int mypipefd[2];
	int ret;
	char buf[100];

	write(1, "OUI\n", 4);
	ret = pipe(mypipefd);
	if (ret == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();

	if (pid == 0) {
		printf("Child Process\n");
		write (mypipefd[1], "Hello there!", 12);
	} else {
		printf("Parent Process\n");
		read(mypipefd[0], buf, 20);
		write(1, buf, 12);
		write(1, "\n", 1);
	}
	close(mypipefd[0]);
	write(1, "NON\n", 4);
	close(mypipefd[1]);
	write(1, "ALAL\n", 5);
	return (0);
}
