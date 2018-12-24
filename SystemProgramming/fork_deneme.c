#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h> 

int main(){
	fork();
	printf("L0 %d\n", getpid());
	fork();
	printf("L1 %d\n", getpid());
}