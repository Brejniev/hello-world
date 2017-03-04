#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


pid_t safeFork() {
	pid_t p = fork();
	if( p<0 ) { exit(1); }
	return p;
}


int main( int argc, char *argv[], char *envp[] ) {
	
	pid_t p;
	int i=0;

	p = safeFork();
	if( p==0 ) {
		char *echo = "/usr/bin/echo";
		char *echoArgs[] = { echo, "Hello ", NULL };
		execve( echo, echoArgs, envp );
		exit(1);
	}

	wait(NULL);
	fprintf( stdout, "World !\n" );

	return 0;

}


