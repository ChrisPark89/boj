#include <stdio.h>

// find ascending lis and decending lis in both way

int main(void)
{
  int a[1001] = {0,};
  int du[1001] = {0,};
  int dd[1001] = {0,};
  int n, i, j;
  int max = 0;

  //get num
  scanf("%d", &n);
  for(i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
    du[i] = 1;
    dd[i] = 1;
  }

  //lis
  for(i=1; i<=n; i++)
  {
    for(j=1; j<i; j++)
    {
      if(a[i] > a[j] && du[j] + 1 > du[i] )
      {
        du[i] = du[j] + 1;
      }
    }
  }
  //reverse lis
  for(i=n; i>0; i--)
  {
    for(j=n; j>i; j--)
    {
      if(a[i] > a[j] && dd[j] + 1 > dd[i] )
      {
        dd[i] = dd[j] + 1;
      }
    }
  }
  //find max
  for(i=1; i<=n; i++)
  {
    if( max < dd[i] + du[i] - 1 )
    {
      max = dd[i] + du[i] - 1;
    }
  }
  printf("%d", max);
}
