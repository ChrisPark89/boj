#include <stdio.h>

/*
 *
 * 
 * */
int max(int a, int b);

int main(void)
{
  int t, n, i, j;
  int arr[2][100001] = {0,};
  int total[2][100001] = {0,};

  scanf("%d", &t);

  for(i=0; i<t; i++)
  {
    // number of row
    scanf("%d", &n);
    // get array
    for(j=1; j<=n; j++)
    {
      scanf("%d", &arr[0][j]);
    }
    for(j=1; j<=n; j++)
    {
      scanf("%d", &arr[1][j]);
    }
    //initial
    total[0][0] = 0;
    total[1][0] = 0;
    total[0][1] = arr[0][1];
    total[1][1] = arr[1][1];
    //recurrence
    for(j=2; j<=n; j++)
    {
      total[0][j] = arr[0][j] + max(total[1][j-1], total[1][j-2]);
      total[1][j] = arr[1][j] + max(total[0][j-1], total[0][j-2]);
    }
    printf("%d\n", max(total[0][n], total[1][n]));
  }


  return 0;
}
 
int max(int a, int b)
{
  return a > b ? a : b;
}
