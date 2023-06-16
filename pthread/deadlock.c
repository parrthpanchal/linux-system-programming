#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<pthread.h>



pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
int counter = 0;


void *func1(void *pvParameter) {


	while(1) {

		pthread_mutex_lock(&mutex1);
		pthread_mutex_lock(&mutex2);
		printf("%d\n",counter);
		counter+=1;
		pthread_mutex_unlock(&mutex2);
		pthread_mutex_unlock(&mutex1);
		sleep(1);

	}

	pthread_exit(0);
}


void *func2(void *pvParameter) {


	while(1) {

		pthread_mutex_lock(&mutex2);
		pthread_mutex_lock(&mutex1);
		printf("%d\n",counter);
		counter+=2;
		pthread_mutex_unlock(&mutex1);
		pthread_mutex_unlock(&mutex2);
		sleep(1);

	}

	pthread_exit(0);
}


int main() {


	pthread_t t1,t2;

	pthread_mutex_init(&mutex1,0);
	pthread_mutex_init(&mutex2,0);

	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);

	pthread_join(t1,0);
	pthread_join(t2,0);

	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);

	exit(0);

}
