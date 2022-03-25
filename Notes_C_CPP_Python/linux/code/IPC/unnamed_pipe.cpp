/*
The input parameter is an array of two file descriptors fd[0] and fd[1]. A file descriptor is
in fact an integer value. The system call returns a –1 in case of a failure. If the call is
successful, it will return two integer values which are file descriptors fd[0]&fd[1]. In
half-duplex pipes, fd[0] and fd[1] are used for reading and writing, respectively.
Unnamed pipes are used b/w related process(like child and parent)
*/


#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() 
{
	int ret_val;
	int pfd[2];
	char buff[32];
	char string1[]="String for pipe I/O";

	ret_val = pipe(pfd);                 /* Create pipe */
	if (ret_val != 0) 
	{             /* Test for success */
		printf("Unable to create a pipe; errno=%d\n",errno);

		exit(1);                         /* Print error message and exit */
	}
	if (fork() == 0) 
	{
		/* child program */
		close(pfd[0]); /* close the read end */
		ret_val = write(pfd[1],string1,strlen(string1)); /*Write to pipe*/
		if (ret_val != strlen(string1)) 
		{
		printf("Write did not return expected value\n");
		exit(2);                       /* Print error message and exit */
		}
	}
	else 
	{
		/* parent program */
		close(pfd[1]); /* close the write end of pipe */
		ret_val = read(pfd[0],buff,strlen(string1)); /* Read from pipe */
		if (ret_val != strlen(string1)) 
		{
			printf("Read did not return expected value\n");
			exit(3);                       /* Print error message and exit */
		}
		printf("parent read %s from the child program\n",buff);
	}
	exit(0);
}