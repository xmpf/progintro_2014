#include <stdio.h>
#include <stdlib.h>

// qsort:
// (void *base, size_t nmemb, size_t size, int (*compar ) (const void *, const void * ))

#define true 1
#define false 0

void printout (int *A, int *B, int N) {
  int i;
  for (i = 0; i < N; i++) {
    printf ("A: %d\n", A[i]);
    printf ("B: %d\n\n", B[i]);
  }
}

int compare (const void *p, const void *q)
{
  return ( *(int *)p - *(int *)q );
}

int main()
{
  int N;
  int i;

  int min;
  int max;

  int bVar = false;

  int *A;
  int *B;

  scanf ("%d", &N);

  A = (int *)malloc (N * sizeof (int)); //allocate memory for array A
  B = (int *)malloc (N * sizeof (int)); //allocate memory for array B

  if (A == NULL || B == NULL) {
    printf ("Error: Unable to allocate memory!\n");
    return -1;
  }

  for (i = 0; i < N; i++) {
    scanf ("%d", &A[i]);
  }
  for (i = 0; i < N; i++) {
    scanf ("%d", &B[i]);
  }

  qsort (A, N, sizeof (int), compare);
  qsort (B, N, sizeof (int), compare);

  i = 0;
  min = (A[N - 1] > B[N - 1]) ? A[N - 1] : B[N - 1];
  max = 0;

  while (i < N) {
    if (A[i] != B[i]) {

      if (A[i] > B[i] && min > B[i])
        min = B[i];
      else if (A[i] < B[i] && min > A[i])
        min = A[i];

      if (A[i] > B[i] && max < A[i])
        max = A[i];
      else if (A[i] < B[i] && max < B[i])
        max = B[i];

      bVar = true;
    }
    i++;
  }
  if (!bVar)
    printf ("yes\n");
  else
    printf ("no %d %d\n", min, max);

  free (A);
  A = NULL;

  free (B);
  B = NULL;

  return 0;
}
