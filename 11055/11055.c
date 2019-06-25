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
  }

  //dp 
  for(i=1; i<=n; i++)
  {
    d[i] = a[i];
    for(j=1; j<i; j++)
    {
      if(a[i] > a[j] && d[j] + a[i] > d[i])
      {
        d[i] = d[j] + a[i];
      }
    }
    if( d[i] > max )
    {
      max = d[i];
    }
  }
  printf("%d", max);
}

