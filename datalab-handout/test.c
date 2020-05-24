#include <stdio.h>

int main(){

  // int y = 0x7FFFFFFF;
  // printf("y = %d\n", y);
  // int z = y + y + 2;

  // printf("z = %d\n", z);
  // int W = !5;

  // printf("W = %d\n", W);
  // int x = 0xFFFFFFFF;
  // int y = 0xAA;
  // int z = (y<<24) | (y<<16) | (y<<8) |y;
  // int w = !((z&x)^z);
  //
  // printf("%d\n",w);
  int x = 0x80000000;
  int y = 0x7FFFFFFF;
  int l;
  int sbx = (x>>31)&1;
  int sby = (y >> 31)&1;
  int sbl;
  l = x + (~y)+ 1;
  printf("l = %d\n", l);
  sbl = (l>>31)&1;
  printf("sbx = %d\nsby = %d\n sbl = %d\n",sbx,sby,sbl);
  int ans = sbx & (sbx^sby); // either x should be negative and  y should be positive
  printf("ans1 = %d\n", ans);
  ans = ans |((!(sbx^sby))&&sbl); // or x and y are of same sign and l is negative
  printf("ans2 = %d\n", ans);

  // return ((ans |(!l)));
  return 0;
}
