#include <stdio.h>

int main(int argc, char const *argv[]){
	int matris[1000][1000];
	int sabit[1000];

	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 1000; j++){
			matris[1000][1000] = matris[1000][1000] * sabit[1000];
		}
	}

	return 0;
}