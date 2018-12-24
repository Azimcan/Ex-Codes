#include <stdio.h>
#include <pthread.h>

int counter;

void *thread_func(void *_tn){
	for (int i = 0; i < 100000; i++){
		counter++;
	}
	return NULL;
}

int main(){
	int N = 5;
	pthread_t t[N];
	for (int i = 0; i < N; i++){
		pthread_create(&t[i], NULL, thread_func, NULL);
	}
	for (int i = 0; i < N; i++){
		pthread_join(t[i], NULL);
	}
	printf("%d\n", counter);
	return 0;
}