
/**************杨辉三角*******************/
#include <stdio.h>
int main() {
  int N;
  while (~scanf("%d", &N)) {
    int A[N][N];
    int i, j;
    for (i = 0; i < N; i++) A[i][0] = A[i][i] = 1;
    for (i = 2; i < N; i++)
      for (j = 1; j < i; j++) A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
    for (i = 0; i < N; i++) {
      for (j = 0; j < i; j++) {
        printf("%d ", A[i][j]);
      }
      if (j == i) printf("%d", A[i][j]);
      printf("\n");
    }
    printf("\n");
  }
}
