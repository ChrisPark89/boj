#include <stdio.h>

int main(void)
{
  int a[1001] = {0,};
  int d[1001] = {0,};
  int x = 1;
  int n, i, j;

  //get num
  scanf("%d", &n);
  for(i=1; i<=n; i++)
  {
    scanf("%d", &a[i]);
  }

  //dp 
  for(i=1; i<=n; i++)
  {
    for(j=x; j>0; j--)
    {
      if(a[i] > d[j-1])
      {
        d[j] = a[i];
        if(j == x)
        {
          x++;
        }
        break; 
      }
      if(a[i] == d[j-1])
      {
        break;
      }
    }
  }

  printf("%d", x-1);
}

