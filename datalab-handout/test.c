#include <stdio.h>

int main(){

  // int y = 0x7FFFFFFF;
  // printf("y = %d\n", y);
  // int z = y + y + 2;

  // printf("z = %d\n", z);
  // int W = !5;

  // printf("W = %d\n", W);
  int x = 0xFFFFFFFF;
  int y = 0xAA;
  int z = (y<<24) | (y<<16) | (y<<8) |y;
  int w = !((z&x)^z);

  printf("%d\n",w);
  return 0;
}
