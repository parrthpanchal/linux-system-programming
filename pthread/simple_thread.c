#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>



void * print_msg (void *pvParameter) {

	printf("%s\n",(char*)pvParameter);
}



int main() {

	pthread_t thread1,thread2;

	pthread_create(&thread1,NULL,print_msg,(void*)"Thread1");
	pthread_create(&thread2,NULL,print_msg,(void*)"Thread2");


	/* Wait for threads to get finished before main continues to execute exit()
	   otherwise the process and all the threads which belongs to this process 
	   will terminate before the threads have completed 
	*/
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	exit(0);

}
