#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h> 

int operation(int a, int b){
	if(fork() == 0){
		wait(NULL);
		return a+b;
	}

	else{
		wait(NULL);
		return a*b;
	}
}

int main(int argc, char const *argv[]){

	if(fork() == 0){
		wait(NULL);
		printf("Child-%d, Sonuc = %d\n", getpid(), operation(5, 6));
	}
	else{
		wait(NULL);
		printf("Parent-%d, Sonuc = %d\n", getpid(), operation(1, 2));		
	}
/*
	int pid = fork();
	int pid2 = fork();

	if(pid == 0){
		wait(NULL);
		int child = 0;
		while(child != 10){
			printf("child-%d = %d\n", getpid(), child);
			child++;
			sleep(1);
		}
	}
	else if(pid2 == 0){
		wait(NULL);

		int child2 = 0;
		while(child2 != 10){
			printf("child-%d = %d\n", getpid(), child2);
			child2++;
			sleep(1);
		}	
	}
	else{
		wait(NULL);
		int parent = 0;
		while(parent != 10){
			printf("parent-%d = %d\n", getpid(), parent);
			parent++;
			sleep(1);
		}		
	}
	
*/
	return 0;
}