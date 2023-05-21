#include<stdio.h>
#include<unistd.h>


int main(void) {

	printf("pid = %d ppid = %d\n",getpid(),getppid());
	while(1){}
	return 0;
}