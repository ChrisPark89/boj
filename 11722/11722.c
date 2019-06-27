#include <stdio.h>

int main(void)
{
  int a[1001] = {0,};
  int d[1001] = {0,};
  int n, i, j;
  int max = 0;

  //get num
  scanf("%d", &n);
  for(i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
    d[i] = 1;
  }

  //dp 
  for(i=1; i<=n; i++)
  {
    for(j=1; j<i; j++)
    {
      if(a[i] < a[j] && d[j] + 1 > d[i] )
      {
        d[i] = d[j] + 1;
      }
    }
    if( max < d[i] )
    {
      max = d[i];
    }
  }
  printf("%d", max);
}

// 10 30 10 20 20 10
//  1  1  2  2  2  3
