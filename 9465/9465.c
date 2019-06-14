#include <stdio.h>

/*
 *
 * 
 * */
int main(void)
{
  int t, n, i, j;
  int arr[2][100001] = {0,};
  int max[2][100001] = {0,};

  scanf("%d", &t);

  for(i=0; i<t; i++)
  {
    // number of row
    scanf("%d", &n);
    // get array
    for(j=0; j<n; j++)
    {
      scanf("%d", &arr[0][j]);
    }
    for(j=0; j<n; j++)
    {
      scanf("%d", &arr[1][j]);
    }

    //initial
    max[0][0] = 0;
    max[1][0] = 0;
    max[0][1] = arr[0][1];
    max[1][1] = arr[1][1];
    //recurrence
    for(j=2; j<n; j++)
    {
      max[0][j] = arr[0][j] + max(max[1][j-1], max[1][j-2]);
      max[1][j] = arr[1][j] + max(max[0][j-1], max[0][j-2]);
    }
  }

  return 0;
}
 
