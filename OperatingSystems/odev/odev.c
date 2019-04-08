#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int time_arti = 0;
int hata_counter = 0;

void begin(){
  printf("Basla\n");
}
void end(){
  printf("Bitir\n");
}
void hata(){
  printf("hata%d\n", hata_counter++);
}

struct S{
  int *row_A;
  int *row_B;
  int *cell;
  int *row_size;
};

typedef struct S thread_params;

int **matrisDimension(int **matris_A, int **matris_B, int *size);
void *plusCounter(void *params); //int *row_A, int *row_B, int *cell, int row_size);
int **transpoz(int **matris, int row, int col);
int **creatMatris(int row, int col);
void printMatris(int **matris, int row, int col);

int main(int argc, char const *argv[]){
  int **matris_A;
  int **matris_B;
  int **result;
  int size[3];

  // Arguman controller
  if(argc != 4){
    fprintf(stderr, "usage: a.out <integer value>\n");
    exit(-1);
  }

  // program_name A B C
  // AxB, BxC matris carpim
  size[0] = atoi(argv[1]); // A
  size[1] = atoi(argv[2]); // B
  size[2] = atoi(argv[3]); // C

  matris_A = creatMatris(size[0], size[1]);
  printMatris(matris_A, size[0], size[1]);
  printf("\n");
  
  //sleep(1);

  matris_B = creatMatris(size[1], size[2]);  
  printMatris(matris_B, size[1], size[2]);
  printf("\n");

  result = matrisDimension(matris_A, matris_B, size);
  printMatris(result, size[0], size[2]);

  free(matris_A);
  free(matris_B);
  free(result);

  return 0;
}

int **matrisDimension(int **matris_A, int **matris_B, int *size){
  pthread_t workers[size[2]];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  thread_params args;

  int **matris_result;
  int **matris_transpoz_B;
  
  matris_transpoz_B = transpoz(matris_B, size[1], size[2]);

  matris_result = (int **)malloc(sizeof(int) * size[0]);
  for(int c = 0; c < size[0]; c++){
    matris_result[c] = (int *)malloc(sizeof(int) * size[2]);
    for(int r = 0; r < size[2]; r++){
      args.row_A = matris_A[c];
      args.row_B = matris_transpoz_B[r];
      args.cell = &matris_result[c][r]; 
      args.row_size = &size[1];
      pthread_create(&workers[r], &attr, plusCounter, &args);
      // plusCounter(matris_A[c], matris_transpoz_B[r], &matris_result[c][r], size[1]);
    }
  }

  free(matris_transpoz_B);

  return matris_result;

}

void *plusCounter(void *args){
  thread_params *params = args;
  *params->cell = 0;
  for (int i = 0; i < *params->row_size; i++){
    *params->cell += params->row_A[i] * params->row_B[i];
  }
  pthread_exit(0);
}

int **transpoz(int **matris, int col, int row){
  int **matris_transpoz;
  matris_transpoz = (int **)malloc(sizeof(int) * row);
  for(int r = 0; r < row; r++){
    matris_transpoz[r] = (int *)malloc(sizeof(int) * col);
    for(int c = 0; c < col; c++){
       matris_transpoz[r][c] = matris[c][r];
    }
  }
  return matris_transpoz;
}



int **creatMatris(int row, int col){
  int **matris;
  srand(time(NULL)+1);

  matris = (int **)malloc(sizeof(int) * row);
  for(int i = 0; i < row; i++){
    matris[i] = (int *)malloc(sizeof(int) * col);
    for(int j = 0; j < col; j++){
      matris[i][j] = (rand() % (90)) + 10;
    }
  }
  return matris;
}

void printMatris(int **matris, int row, int col){
  printf("=>%p\n", matris);
  for(int i = 0; i < row; i++){     
    printf("=>%p\t", matris[i]);
    for(int j = 0; j < col; j++){
      printf("%d ", matris[i][j]);
    }
    printf("\n");
  }
}
