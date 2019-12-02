#include <stdlib.h>

int main(void)
{
  int *ptr;
  ptr = (int *)malloc(sizeof(int));
  
  *ptr = 16;
  return (0);
}