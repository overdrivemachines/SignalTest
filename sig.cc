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

void sigchld_handler(int sig);
void sigusr1_handler(int sig);

int main()
{
	// Install signals
	signal(SIGCHLD, sigchld_handler);
	signal(SIGUSR1, sigusr1_handler);



	exit(0);
}

void sigchld_handler(int sig)
{

}

void sigusr1_handler(int sig)
{
	
}