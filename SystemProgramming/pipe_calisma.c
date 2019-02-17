#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	int pid, p[2];
	char buf[1024];
	if(pipe(p) < 0){
		perror("Pipe hatasi ");
		exit(1);
	}
	pid = fork();

	if(pid == 0){
		close(p[1]);
		read(p[0], buf, 16);	
		printf("%s", buf);
	}
	else{
		close(p[0]);
		write(p[1], "Child'a yaz...\n", 16);
	}

	return 0;
}

// =========== 1 ===========
// int main(int argc, char const *argv[]){
// 	int fd[2], pid;
// 	pipe(fd);

// 	pid = fork();
// 	if(pid == 0){
// 		dup2(fd[0], 0);
// 		close(fd[1]);
// 		printf("%d\n", execlp("sort", "sort", 0));
// 	}
	
// 	pid = fork();
// 	if(pid == 0){
// 		dup2(fd[1], 1);
// 		close(fd[0]);
// 		execlp("who", "who", 0);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);
// 	wait(0);
// 	wait(0);
// }