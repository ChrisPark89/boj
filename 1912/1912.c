#include <stdio.h>

int main(void)
{
  int a[100001] = {0,};
  int d[100001] = {0,};
  int n, i, j;
  int max = -1000;

  //get num
  scanf("%d", &n);
  for(i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
  }

  //dp 
  for(i=1; i<=n; i++)
  {
    d[i] = a[i];
    if( d[i-1] > 0 && d[i-1] + a[i] > 0 )
    {
      d[i] = d[i-1] + a[i];
    }

    if( d[i] > max )
    {
      max = d[i];
    }
  }
  printf("%d", max);
}

