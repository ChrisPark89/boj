#include <stdio.h>

int main(void)
{
  int n, i, j;
  int d[31]={0,};
  int multiplier;

  //get num
  scanf("%d", &n);

  //f(0) = 1
  //f(2) = 3
  //f(n) = f(n-2)*3 + f(n-4)*2 + f(n-6)*2 ... f(0)*2

  d[0] = 1;
  d[1] = 0;
  d[2] = 3;
  for(i=3; i<=n; i++)
  {
    if(i%2 != 0)
      d[i] = 0;
    else
    {
      for(j=2; j<=i; j+=2)
      {
        multiplier = j == 2 ? 3 : 2;
        d[i] += d[i-j] * multiplier;
      }
    }
  }
  printf("%d", d[n]);
}


