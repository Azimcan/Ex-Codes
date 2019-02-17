#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// =========== 1 ===========
// #define NUM_THREADS 8

// char *messages[NUM_THREADS];

// void *printHello(void *thread_id){
// 	long task_id;
// 	sleep(1);
// 	task_id = (long)thread_id;
// 	printf("Thread %ld. %s\n",task_id, messages[task_id]);
// 	pthread_exit(NULL);
// }
// int main(int argc, char const *argv[]){
// 	pthread_t threads[NUM_THREADS];
// 	long task_id[NUM_THREADS];
// 	int rc, t;
// 	messages[0] = "English:";
// 	messages[1] = "French:";
// 	messages[2] = "Spanish:";
// 	messages[3] = "Klingon:";
// 	messages[4] = "Germna:";
// 	messages[5] = "Russian:";
// 	messages[6] = "Japan:";
// 	messages[7] = "Latin:";

// 	for (t = 0; t < NUM_THREADS; t++){
// 		task_id[t] = t; 
// 		printf("Creating thread%d\n", t);
// 		rc = pthread_create(&threads[t], NULL, printHello, (void*)task_id[t]);
// 		if(rc){
// 			printf("error\n");
// 			exit(-1);
// 		}
// 	}
// 	pthread_exit(NULL);
// 	return 0;
// }

// =========== 2 ===========
// void *thread_routine(void *args){
// 	printf("Thread is Created\n");
// 	sleep(30);
// 	printf("After Sleep\n");
// }

// int main(int argc, char const *argv[]){
// 	pthread_t	thread_id;
	
// 	pthread_create(&thread_id, NULL, thread_routine, NULL);
// 	sleep(3);
	
// 	printf("Main Thread\n");
// 	pthread_cancel(thread_id);
	
// 	printf("The End\n");
// 	return(0);
// }

// =========== 3 ===========
// int counter;

// void *thread_func(void *_tn){
// 	for (int i = 0; i < 1000000; i++){
// 		counter++;
// 	}
// 	return NULL;
// }

// int main(){
// 	int N = 5;
// 	pthread_t t[N];
// 	for (int i = 0; i < N; i++){
// 		pthread_create(&t[i], NULL, thread_func, NULL);
// 	}
// 	for (int i = 0; i < N; i++){
// 		pthread_join(t[i], NULL);
// 	}
// 	printf("%d\n", counter);
// 	return 0;
// }

// =========== 4 ===========
#define MAX 18
#define MAX_THREAD 4

int a[] = {98, 2, 43, 42, 9, 49, 58, 6, 80, 87, 2, 87, 4, 98, 4, 11, 8, 89};
int sum[4] = {0};
int part = 0;

void *sum_array(void *array){
	int thread_part = part++;
	for (int i=thread_part*(MAX/4); i<(thread_part+1)*(MAX/4); i++){
		sum[thread_part] += a[i];
	}
}

int main(){
	clock_t tStart = clock();

	pthread_t threads[MAX_THREAD];
	for (int i=0; i<MAX_THREAD; i++){
		pthread_create(&threads[i], NULL, sum_array, NULL);
	}
	for (int i = 0; i < MAX_THREAD; i++){
		pthread_join(threads[i], NULL);
	}
	
	int total_sum = 0;
	for(int i=0; i<MAX_THREAD; i++){
		total_sum += sum[i];
	}
	printf("%d\n", total_sum);

	printf("Time Taken: %f\n", (double)(clock() - tStart)/CLOCKS_PER_SEC );
	return 0;
}