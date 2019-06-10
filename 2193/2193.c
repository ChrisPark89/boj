#include <stdio.h>


/*
 * f(1,0) = 0
 * f(1,1) = 1
 * f(n,0) = f(n-1,1) + f(n-1,0)
 * f(n,1) = f(n-1,0)
 * */
int main(void)
{
  long int n, i;
  long int cnt[91][2] = {0, };
  long int result = 0;
    
  scanf("%ld", &n);

  //initial
  cnt[1][0] = 0;
  cnt[1][1] = 1;
  //recurrence formular
  for(i=2; i<=n; i++)
  {
    cnt[i][0] = cnt[i-1][1] + cnt[i-1][0]; 
    cnt[i][1] = cnt[i-1][0];
  }

  result = cnt[n][0] + cnt[n][1];
  printf("%ld", result);

  return 0;
}
