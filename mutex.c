#include "apue.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIALIZER;
int total = 0;

void* tfn(void * arg)
{
	int num = *((int *) arg);
	long d2num = 3*num;
	pthread_mutex_lock(&hashlock);
	printf("In thread %lu arg:%d.\n", (unsigned long)pthread_self(), num);
	total += num;
	printf("Thread over!!! arg:%d\n", num);
	pthread_mutex_unlock(&hashlock);
	return (void*)(d2num);
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	int num;
	void* tret;
	while(scanf("%d", &num) == 1){
		pthread_create(&tid, NULL, tfn, (void*) &num);
		pthread_join(tid, &tret);  //why 2 * ?
		printf("Thread exit code: %ld\n", (long)tret);
	}
	pthread_mutex_destroy(&hashlock);
	printf("Main thread %lu is over.\n",(unsigned long)pthread_self());
	printf("total: %d", total);
}
