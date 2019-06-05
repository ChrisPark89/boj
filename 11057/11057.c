#include <stdio.h>


/*
 * f(n,0) = f(n-1,0)
 * f(n,1) = f(n-1,0)+f(n-1,1)
 * f(n,2) = f(n-1,0)+f(n-1,1)+f(n-1,2) = f(n,1)+f(n-1,2)
 * f(n,3) = f(n-1,0)+f(n-1,1)+f(n-1,2)+f(n-1,3) = f(n,2)+f(n-1,3)
 * ...
 * f(n,x) = f(n,x-1)+f(n-1,x)
 * */
int main(void)
{
  int i,j,n;
  int count[1001][10]={0,};
  int result = 0;

  scanf("%d", &n);
  
  //initial case
  for(j=0; j<=9; j++)
  {
    count[1][j] = 1;
  }

  for(i=2; i<=n; i++)
  {
    count[i][0] = count[i-1][0];
    for(j=1; j<=9; j++)
    {
      count[i][j] = (count[i][j-1] + count[i-1][j]) % 10007;
    }
  }

  for(j=0; j<=9; j++)
  {
    result = (result + count[n][j]) % 10007;
  }

  printf("%d", result);

  return 0;
}
