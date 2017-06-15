#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

void go_daemon();
int main() {
	printf("let's run some processes\n");

	pid_t forked_pid;
	int terminated_pid, status; 
	printf("Main program has PID %d\n", (int)getpid());
	system("echo \"Process created with system() has PID : $$\"");

	forked_pid = fork();

	if (forked_pid > 0) { 
		printf("This is the parent process, with ID %d\n", (int)getpid());
		printf("The child's process ID is %d\n", (int)forked_pid);
		terminated_pid = wait(&status);
		printf("Parent proocess waited for %d to end\n", terminated_pid);
		printf("Child process returned %d\n", WEXITSTATUS(status));
	} 
	else if (forked_pid == 0) {
		printf("This is the child process, with ID %d\n", (int)getpid());
		char* arg_list[] = { "/bin/sleep", "3", NULL };
		execv( "/bin/sleep", arg_list );
	}
	else  {
		printf("fork failed!");
		return 1;
	}
	/*
	* now lets go to daemon mode
	*/
	go_daemon();

	while(1);
	return 0;
}

void go_daemon(){
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("Error forking while giong daemon");
		exit(1);
	}
	else if (pid > 0){
		/*parent process now must be terminated*/
		printf("Going daemon mode, don\'t forget to kill  %d\n", (int)pid);
		exit(0);
	}
	else {
		/*
		* "Give up the moorings!"
		* give up access to files, 
		* become leader of a new session
		* get rid of stdin/out/err
		* "Raise the sails!"
		*/
		umask(0);
		setsid();
		chdir("/");
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
}