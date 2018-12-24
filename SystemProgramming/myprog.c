#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	int toplam = 0;
	for(;*argv;++argv){
	//	printf("%s\n", *argv);
		toplam+=atoi(*argv);
	}
		printf("%d\n", toplam);
}