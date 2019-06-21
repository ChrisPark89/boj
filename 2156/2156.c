#include <stdio.h>

int max(int a, int b, int c);

int main(void)
{
  int a[10001] = {0,};
  int d[10001] = {0,};
  int n, i;

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
    d[i] = max(d[i-1], a[i]+d[i-2], a[i]+a[i-1]+d[i-3]);
  }

  printf("%d", d[n]);
}

int max(int a, int b, int c)
{
  if(a > b)
  {
    return a > c ? a : c; 
  }
  else
  {
    return b > c ? b : c;
  }
}

