#include <stdio.h>
#define F(a) (a*a)

int main(){
	int dilimsayisi = 10000000;
	float x, x_alt, x_ust;
	float toplam, h, intg;
	x_alt = 1;
	x_ust = 4;
	h = (x_ust - x_alt) / dilimsayisi;
	x = x_alt;
	toplam = 0;

	while(  x < x_ust ){
		toplam += F(x);
		x += h;
	}
	intg = h * toplam;

	printf("F(x) fonksiyonun (1, 4) kısmi integrali: %f\n", intg);

}