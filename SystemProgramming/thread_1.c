#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void fonk1(void);

int main(int argc, char const *argv[]){
	clock_t tStart = clock();


	printf("Ana is parcacigi baslar....\n");

	pthread_t td1;
	
	int p = pthread_create(&td1, NULL, fonk1, NULL);
	if (p != 0){
		perror("Thread problem");
		exit(1);
	}
	for (int j = 0; j <= 1000; j++){
		printf("Ana is parcacigi calisir: %d\n", j);
	}
	pthread_join(td1, NULL);
	printf("Ana is parcacigi sonlanir....\n");

	printf("Time Taken: %f\n", (double)(clock() - tStart)/CLOCKS_PER_SEC );

	return 0;
}

void fonk1(void){
	int i;
	for (i = 1; i <= 1000; i++){
		printf("Yaratilan is parcacigi: %d\n", i);
	}
}