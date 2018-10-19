#include <stdio.h>
#include <stdlib.h>

int deneme1();
int deneme2();
int deneme3();

int main() {
	deneme3();

	return 0;
}

int deneme3(){
	int a = 10;
	int *p = &a;;
	int **q = &p;


	printf("%d\n", a);
	printf("%d\n", &a);

	printf("%d\n", p);
	printf("%d\n", &p);
	printf("%d\n", *p);

	printf("%d\n", q);
	printf("%d\n", &q);
	printf("%d\n", **q);

}

int deneme2(){
  int a = 10;

  int *q = (int *)malloc(sizeof(int) * a);
  for(int i = 0; i < a; i++){
  	q[i] = i * i;
  }

  for(int i = 0; i < a; i++){
  	printf("%-5d", q[i]);
  	printf("%d\n", i);
  }
  printf("\n");

}

int deneme1(){
	int *p;
	int a = 10;

	p = &a;

	printf("%d\n", *p);
	printf("%d\n", a);

	//printf("%d\n", &p);
	//printf("%d\n", p);
	//printf("%d\n", &a);
	
}