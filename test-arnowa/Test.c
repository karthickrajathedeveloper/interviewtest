#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

int *vectorV; // Vector
int **matrixM; // Matrix
int N, k;

int *getVector(int n) {
  int *m;
  m = (int *)malloc(n * sizeof(int));
  if (!m) {
    fprintf(stderr, "Vector Memory error!\n");
    exit(-1);
  }
  return m;
}

void freeMemory() {
  int i;
  free(vectorV);
  vectorV = NULL;
  for (i = 0; i < N; i++) {
    free(matrixM[i]);
    matrixM[i] = NULL;
  }
  free(matrixM);
  matrixM = NULL;
}

int main(int argc, char *argv[]) {
  int i, j;
  k = 5;
  N = 10;

  vectorV = (int *)getVector(k);

  for (i = 0; i < k; i++)
    vectorV[i] = i;
  for (i = 0; i < k; i++)
    fprintf(stderr, "%d ", vectorV[i]);
  fprintf(stderr, "\n\n");

  matrixM = (int **)malloc(N * sizeof(int *));
  if (!matrixM) {
    fprintf(stderr, "Matrix Memory error!\n");
    exit(-1);
  }
  for (i = 0; i < N; i++) {
    matrixM[i] = (int *)malloc(k * sizeof(int));
    if (!matrixM[i]) {
      fprintf(stderr, "Matrix Memory error!\n");
      exit(-1);
    }
  }

  for (i = 0; i < N; i++)
    for (j = 0; j < k; j++)
      matrixM[i][j] = i + j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < k; j++)
      fprintf(stderr, "%2d ", matrixM[i][j]);
    fprintf(stderr, "\n");
  }

  fprintf(stderr, "\n");
  freeMemory();
  return (0);
}
