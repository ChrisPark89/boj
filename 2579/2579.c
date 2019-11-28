#include <stdio.h>

int comp_max(int a, int b);

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
  d[0] = 0;
  d[1] = a[1];
  d[2] = a[1]+a[2];
  for(i=3; i<=n; i++)
  {
    d[i] = comp_max(a[i]+a[i-1]+d[i-3], a[i]+d[i-2]);

  }
  printf("%d", d[n]);
}

int comp_max(int a, int b)
{
  return a > b ? a : b;
}

// n-4 n-3     n-2    n-1    n
//
