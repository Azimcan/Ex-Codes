#include <stdio.h>
#include "matrisToplam.h"

int main(){
	int a[2][2] = {{1, 2}, {1, 2}};
	int b[2][2] = {{3, 4}, {3, 4}};
	int c[2][2];	

	toplamMatris(a, b, c);
	printt(c);

	return 0;
}
