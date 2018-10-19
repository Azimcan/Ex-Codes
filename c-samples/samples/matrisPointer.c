#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatris(int **matris, int line, int column);
void creatMatris(int **matris, int line, int column);

int main(void){
	srand(time(NULL));

	int **matris = (int **)malloc(sizeof(int) * 3);

	for(int i = 0; i < 4; i++){
		matris[i] = (int *)malloc(sizeof(int) * 3);
	}																									//matris[3][4] matris oluştu
	
	creatMatris(matris, 3, 4);	
	printMatris(matris, 3, 4);

	return 0;
}

void creatMatris(int **matris, int line, int column){
	for(int i = 0; i < line; i++){
		for(int j = 0; j < column; j++){
			 matris[i][j] = 10 + rand() % 89;
		}
	}
}

void printMatris(int **matris, int line, int column){
	for(int i = 0; i < line; i++){				
		for(int j = 0; j < column; j++){
			printf("%-4d", matris[i][j]);
		}
		printf("\n\n");
	}
} 	