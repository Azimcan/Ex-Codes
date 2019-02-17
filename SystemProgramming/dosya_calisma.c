#include <stdio.h> /* perror() için */
#include <fcntl.h>
#include <stdlib.h>


char *kaynak = "kaynak";
char *kopya = "kopya";

int main(){ 
	int k_tanimlayici, y_tanimlayici, okunan_miktar; 
	char buffer[100];

	k_tanimlayici = open(kaynak, O_RDONLY);
	y_tanimlayici = creat(kopya, 0644);
	
	okunan_miktar = read(k_tanimlayici, buffer, 20);
	
	printf("%d\n", k_tanimlayici);
	printf("%d\n", y_tanimlayici);
	
	if( okunan_miktar < 0 ){
		perror("deneme");
		exit(1);
	}
 	
 	else if( okunan_miktar == 0 ){
 		write(2, "Dosyada veri yok\n", 29);
 		exit(0);
	}
	else{

		write(y_tanimlayici, buffer, okunan_miktar);

		close(k_tanimlayici);
		close(y_tanimlayici);		
	}

	write(1, buffer, okunan_miktar);
	printf("\n");
}