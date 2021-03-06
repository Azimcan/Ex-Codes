#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

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
void matrisFree(int **matris, int row);
void printMatris(int **matris, int row, int col);


int main(int argc, char const *argv[]){
  srand(time(NULL));
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
  
  matris_B = creatMatris(size[1], size[2]);  
  printMatris(matris_B, size[1], size[2]);
  printf("\n");

  result = matrisDimension(matris_A, matris_B, size);
  printMatris(result, size[0], size[2]);

  
  printf("hata1\n");
  matrisFree(matris_A, size[0]);
  printMatris(matris_A, size[0], size[1]);

  printf("hata2\n"); 
  matrisFree(matris_B, size[1]);
  printMatris(matris_B, size[1], size[2]);

  printf("hata3\n");
  matrisFree(result, size[0]);
  printMatris(result, size[0], size[2]);

  return 0;
}

int **matrisDimension(int **matris_A, int **matris_B, int *size){
  pthread_t workers[size[0]*size[2]];
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
      pthread_create(&workers[r], NULL, plusCounter, &args);
    }
  }
  for (int i = 0; i < size[0]*size[2]; i++){
    pthread_join(workers[i], NULL);
  }

  matrisFree(matris_transpoz_B, size[2]);

  return matris_result;

}

void *plusCounter(void *args){
  thread_params *params = args;
  int result = 0;
  for (int i = 0; i < *params->row_size; i++){
    result += params->row_A[i] * params->row_B[i];
  }
  *params->cell = result;
    printf("%d\n", result);
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

  matris = (int **)malloc(sizeof(int) * row);
  for(int i = 0; i < row; i++){
    matris[i] = (int *)malloc(sizeof(int) * col);
    for(int j = 0; j < col; j++){
      matris[i][j] = (rand() % (90)) + 10;
    }
  }
  return matris;
}

void matrisFree(int **matris, int row){
  int r = row;
  while(r) 
    free(matris[--r]);
  free(matris[r]);
}

void printMatris(int **matris, int row, int col){
  printf("=>%p\n", matris);
  for(int r = 0; r < row; r++){     
    printf("=>%p\t", matris[r]);
    for(int c = 0; c < col; c++){
      printf("%d ", matris[r][c]);
    }
    printf("\n");
  }
}
