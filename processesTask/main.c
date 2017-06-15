#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("let's run some processes\n");

	pid_t forked_ch_pid; 
	printf("Main program has PID %d\n", (int)getpid());
	system("echo \"Process created with system() has PID : $$\"");
	/*exec("/bin/echo", "\"Process created with exec() has PID : $$\"");*/

	forked_ch_pid = fork();

	if (forked_ch_pid != 0) 
	{
	printf("This is the parent process, with ID %d\n", (int)getpid());
	printf("The child's process ID is %d\n", (int)forked_ch_pid);
	} 
	else 
	{
	
	printf("This is the child process, with ID %d\n", (int)getpid());
	char* arg_list[] = { "/bin/echo", "Hello from exec()",  NULL };
	execv( "/bin/echo", arg_list );
	}
}