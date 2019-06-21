#include <stdio.h>


int main(void)
{
  int a[1001] = {0,};
  int d[1001] = {0,};
  int x, y;
  int n, i;

  //get num
  scanf("%d", &n);
  for(i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
  }

  //dp 
  x = 0;
  y = 0;
  d[0] = 0;
  for(i=1 ; i<=n; i++)
  {
  }

  printf("%d", d[n]);
}

