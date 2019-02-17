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

	// Istemci icin port ve ip adresi isletim sistemi tarafindan belirtilecek
	struct sockaddr_in cli = {AF_INET, INADDR_ANY, INADDR_ANY};

	// Sunucu adresi
	struct sockaddr_in srv = {AF_INET, PORT, inet_addr("127.0.0.1")};

	printf("Istemci: basliyor...\n");

	// SOCK_STREAM tipinde internet soleti olustur
	if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("Soket problemi");
		exit(1);
	}

	// Soketi port ve ip numarasina bagla
	if(bind(s, (struct sockaddr *) &cli, SIZE) < 0){
		perror("Baglama hatasi");
		exit(1);
	}

	// Sunucuya baglanmayi dene
	len = SIZE;
	if(connect(s, (struct sockaddr *)&srv, len) < 0){
		perror("Baglanti hatasi");
	}

	// Mesaji s soketi araciligiyla sunucuya gonder
	n = send(s, "Gonderilen Mesaj", 30, 0);
	if(n < 0){
		perror("Gonderim hatasi");
		exit(1);
	}
	printf("Istemci: istek gonderildi...\n");
	
	// Sunucudan gelen cevabi alip yazdir
	n = recv(s, buf, sizeof(buf), 0);
	write(1, buf, n);

	// Soketi kapat ve cik
	close(s);
	printf("TCP istemci sonlandi...\n");
	exit(0);
}
