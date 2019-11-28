#include <stdio.h>

int main(void)
{
  int n, i, j;
  int d[100001]={0,};

  //get num
  scanf("%d", &n);

  for(i=1; i<=n; i++)
  {
    d[i] = i;
  }

  for(i=1; i<=n; i++)
  {
    for(j=1; j*j<=i; j++)
    {
      if( d[i-j*j] + 1 < d[i] )
      {
        d[i] = d[i-j*j] + 1;
      }
    }
  }
  printf("%d", d[n]);
}


