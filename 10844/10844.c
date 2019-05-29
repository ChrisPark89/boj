#include <stdio.h>

int main(void)
{
  int len, n, x;
  int count[101][10]={0,};
  int result = 0;

  scanf("%d", &len);

  for(x=1; x<=9; x++)
  {
    count[1][x] = 1;
  }
  for(n=2; n<=len; n++)
  {
    count[n][0] = count[n-1][1];
    count[n][9] = count[n-1][8];
    for(x=1; x<=8; x++)
    {
        count[n][x] = (count[n-1][x-1] + count[n-1][x+1]) % 1000000000;
    }
  }

  for(x=0; x<10; x++)
  {
    result = (result + count[len][x]) % 1000000000;
  }

  printf("%d\n", result); 
}
