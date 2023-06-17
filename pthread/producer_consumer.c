#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<pthread.h>


pthread_mutex_t mutex0;
pthread_cond_t cond;
int total_msg = 12;
int msg = 0;


void *producer(void *pvParameter) {

	while(total_msg > 0) {

		pthread_mutex_lock(&mutex0);
		msg = total_msg;
		total_msg--;
		printf("[Producer] Sent Message : %d\n",msg);
		pthread_mutex_unlock(&mutex0);
		pthread_cond_signal(&cond);
		sleep(1);

	}

	pthread_exit(0);

}

void *consumer(void *pvParameter) {

	while(total_msg > 0) {

		pthread_mutex_lock(&mutex0);
		pthread_cond_wait(&cond,&mutex0);
		printf("[Consumer] Received Message : %d\n",msg);
		msg = 0;
		pthread_mutex_unlock(&mutex0);
	}

	pthread_exit(0);
	
}



int main() {

	pthread_t p,c;

	pthread_mutex_init(&mutex0,0);
	pthread_cond_init(&cond,0);

	pthread_create(&c,0,consumer,0);
	pthread_create(&p,0,producer,0);

	pthread_join(p,0);
	pthread_join(c,0);

	pthread_mutex_destroy(&mutex0);
	pthread_cond_destroy(&cond);

	exit(0);

}






