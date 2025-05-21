#include <stdio.h>

int main()
{

  int A[2][2], B[2][2], C[2][2];
  int i, j, k;

  // Input Matrix A
  printf("Enter elements of 2x2 Matrix A:\n");
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    {
      printf("A[%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }

  // Input Matrix B
  printf("Enter elements of 2x2 Matrix B:\n");
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    {
      printf("B[%d][%d]: ", i, j);
      scanf("%d", &B[i][j]);
    }

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    {
      C[i][j] = 0;
      for (k = 0; k < 2; k++)
        C[i][j] += A[i][k] * B[k][j];
    }


    printf("Resultant Matrix C = A * B:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
