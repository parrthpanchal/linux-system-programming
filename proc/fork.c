#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>




int main (void) {


	pid_t id = fork();


	if(id < 0) {
		printf("Failed to create the child process\n");
	}


	if(id>0) {
		printf("Exclusive parent section\n");
	} else {
		printf("Exclusive child section\n");
		printf("PPID : %d\n",getppid());

	}

	while(1);
	exit(0);

}