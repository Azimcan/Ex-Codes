#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h> 

void fork0(){
	pid_t pid = fork();
	if(pid == -1){

	}

	if(pid == 0)
		printf("Hello from child\n");
	else
		printf("Hello from parent\n");
}

void fork1(){
	int x = 1;
	pid_t pid = fork();

	if(pid == 0)
		printf("Child has x = %d\n", ++x);
	else
		printf("Parent has x = %d\n", --x);
	printf("By from process %d with x = %d\n", getpid(), x );
}

void fork2(){
	printf("L0 %d\n", getpid());
	fork();
	printf("L1 %d\n", getpid());
	fork();
	printf("Bye %d\n", getpid());
}

void fork3(){
	printf("L0 %d\n", getpid());
	if(fork() != 0){
		printf("L1 %d\n", getpid());
		if(fork() != 0){
			printf("L2 %d\n", getpid());
			fork();
		}
	}
	printf("Bye %d\n", getpid());
}

void fork4(){
	printf("L0\n");
	if(fork() == 0){
		printf("L1\n");
		if(fork() == 0){
			printf("L2\n");
			fork();
		}
	}
	printf("Bye\n");
}

void fork5(){
	fork();
	exit(0);
}

void fork6(){
	if(fork() == 0){
		printf("Terminating Child, PID = %d\n", getpid());
		exit(0);
	}
	else{
		printf("Running Parent, PID = %d\n", getpid());
		while(1){}
	}
}


void fork7(){
	if(fork() == 0){
		printf("Terminating Child, PID = %d\n", getpid());
		while(1){}
	}
	else{
		printf("Running Parent, PID = %d\n", getpid());
		exit(0);
	}
}

void fork8(){
	int child_status;
	if(fork() == 0){
		printf("HC: hello from child\n");
	}
	else{
		printf("HP: hello from parent\n");
		wait(&child_status);
		printf("CT: child has terminating\n");
	}
	printf("Bye\n");
	exit(0);
}

void deneme1(){
	fork();
	fork();
	fork();
	fork();
	printf("hello\n");	
}

void deneme2(){
	pid_t pid;
	if((pid = fork()) == 0)
		printf("1");
	else
		printf("2");
	printf("3");
}

int main(){
	fork3();

	return 0;
}