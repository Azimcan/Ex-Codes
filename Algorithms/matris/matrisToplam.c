#include <stdio.h>
#include "matrisToplam.h"

void toplamMatris(int a[2][2], int b[2][2], int c[2][2]){
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){

			c[i][j] = a[i][j] + b[i][j];

		}	
	}
}

void printt(int c[2][2]){
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			printf("%d", c[i][j]);
		}	
	}
}
