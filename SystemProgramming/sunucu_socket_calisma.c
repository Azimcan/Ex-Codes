#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 3000
#define SIZE sizeof(struct sockaddr_in)

int main(int argc, char const *argv[]){
	int n, s, ns, len;
	char buf[1024];

	struct sockaddr_in srv = {AF_INET, PORT, INADDR_ANY};
	struct sockaddr_in cli; // Istemci adresi icin 

	int cli_len = SIZE;

	printf("Sunucu: basliyor...\n");

	// SOCK_STREAM tipinde soket olusturur
	s = socket(AF_INET, SOCK_STREAM, 0);
	if(s < 0){
		perror("Soket hatasi");
		exit(1);
	}

	// Soketi istenen port ve tum ip adresine bagla 
	if(bind(s, (struct sockaddr *) &srv, SIZE) < 0){
		perror("Baglama hatasi");
		exit(1);
	}

	//Dinlemeye basla, en fazla baglanti bekleyen 5 adet istemci olabilir
	if(listen(s, 5) < 0){
		perror("Dinleme hatasi");
		exit(1);
	}

	while(1){
		// Baglanti kabul et, eger sirada bekleyen yoksa, bir baglanti gelinceye kadar bekler 
		ns = accept(s, (struct sockaddr *)&cli, &len);
		if(ns < 0){
			perror("Kabul etme sorunu");
			exit(1);
		}

		// Baglanti saglanan soketi oku
		n = recv(ns, buf, sizeof(buf), 0);
		if(n < 0){
			perror("Okuma sorunu");
			exit(1);
		}
		write(1, buf, n);

		// istemciye cevap yolla
		send(ns, "This is a reply from server\n", 28, 0);
		printf("Sunucu: cevap gonderildi...\n");

		// Soketi kapat ve devam et
		close(ns);
	}
}
