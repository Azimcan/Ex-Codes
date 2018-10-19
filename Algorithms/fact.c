#include <stdio.h>  

unsigned long int fact( unsigned long int n );

int main() {
	for ( int i = 1; i < 21; i++ )  {
		printf("%d : %ld \n", i, fact( i ) );
	}
	return 0;
}

unsigned long int fact( unsigned long int n ) {
	if ( n <= 1 ){									//			-1      
		return 1;											//			-2
	}
	else {													//			-3
		return ( n * fact( n - 1 ) );	//			-4
	}
}