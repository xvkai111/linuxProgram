#include "my.h"

int main()
{
	int pid;
	if((pid=fork()) < 0)
	{
		perror("fail to fork!\n");
		return -1;
	}
	else if(pid == 0)
	{
		printf("%d:child is running.\n", getpid());
		getchar();
		printf("%d:child exit now.\n", getpid());
		exit(0);
	}
	else
	{
		printf("%d:parent is running.\n", getpid());
		wait(NULL);
		printf("%d:parent exit now.\n", getpid());
	}
	exit(0);
}

//ps -aux | grep test1
