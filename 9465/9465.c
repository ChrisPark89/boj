#include <stdio.h>

/*
 * x = the last one's row
 *
 * f(1) = max( arr[0][0], arr[1][0] )
 * f(2) = max( arr[0][0]+arr[1][1], arr[1][0]+arr[0][1] )
 * f(3) = max( f(2)+arr[x^1][2], f(1)+arr[x][2] )
 *
 * f(n) = max( f(n-1)+arr[x^1][n-1], f(n-2)+arr[x][n-1] )
 * 
 * */
int main(void)
{
  int t, n, i, j, x;
  int arr[2][100001];
  int max[100001] = {0,};
  int result[100001] = {0,};
    
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
    // find the solution
    // f(1) = max( arr[0][0], arr[1][0] )
    if(arr[0][0] > arr[1][0])
    {
      max[1] = arr[0][0];
      x = 0;
    }
    else
    {
      max[1] = arr[1][0];
      x = 1;
    }
    // f(2) = max( arr[0][0]+arr[1][1], arr[1][0]+arr[0][1] )
    if(arr[0][0]+arr[1][1] > arr[1][0]+arr[0][1])
    {
      max[2] = arr[0][0]+arr[1][1];
      x = 1;
    }
    else
    {
      max[2] = arr[1][0]+arr[0][1];
      x = 0;
    }
    // f(n) = max( f(n-1)+arr[x^1][n-1], f(n-2)+arr[x][n-1] )
    for(j=3; j<=n; j++)
    {
      if( max[j-1]+arr[x^1][j-1] > max[j-2]+arr[x][j-1] )
      {
        max[j] = max[j-1]+arr[x^1][j-1];
        x = x^1;
      }
      else
      {
        max[j] = max[j-2]+arr[x][j-1];
        x = x;
      }
    }
    
    result[i] = max[n];
    // printf("%d\n", max[n]);
  }

  for(i=0; i<t; i++)
  {
    printf("%d\n", result[i]);
  }

  return 0;
}
 
