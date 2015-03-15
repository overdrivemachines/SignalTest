using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>

pid_t pid;

void sigchld_handler(int sig);
void sigusr1_handler(int sig);

int main()
{
	int status;
	signal(SIGCHLD, sigchld_handler);
	signal(SIGUSR1, sigusr1_handler);

	if (pid = fork())
	{
		printf("Parent\n");

		if (wait(&status))
			printf("p\n");
		else
			printf("q\n");
	}
	else
	{
		printf("Child\n");
		kill(getppid(), SIGUSR1);
		while(true)
			sleep(0);
	}

	exit(0);
}

void sigchld_handler(int sig)
{
	printf("SIGCHLD handler\n");
	exit(0);
}

void sigusr1_handler(int sig)
{
	if (pid > 0)
	{
		printf("Parent SIGUSR1 handler\n");
		kill(pid, SIGUSR1);
	}
	else
	{
		printf("Child SIGUSR1 handler\n");
		exit(0);
	}
}