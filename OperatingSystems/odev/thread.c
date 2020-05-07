#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 10

int sum;
void *runner(void *param);

int main(int argc, char *argv[]){
  pthread_t workers[NUM_THREADS];
  pthread_attr_t attr;


  if(argc != 2){
    fprintf(stderr, "usage: a.out <integer value>\n");
    return(-1);
  }
  if(atoi(argv[1]) < 0){
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return(-1);
  }

  void *upper;

  for (int i = 0; i < NUM_THREADS; i++){
    pthread_create(&workers[i], NULL, runner, argv[1]);
    printf("%d\n", atoi(upper));
  }
  
  for (int i = 0; i < NUM_THREADS; i++){
    pthread_join(workers[i], NULL);
  }

  return 0;
}

void *runner(void *param){
  int upper = atoi(param);
  sum = 0;

  for (int i = 0; i < upper; i++){
    sum += i;
  }
  printf("%d\n", sum);

  pthread_exit(0);

}