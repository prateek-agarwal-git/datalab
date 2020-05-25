#include <stdio.h>
// howManyBits(12) = 5
// *            howManyBits(298) = 10
// *            howManyBits(-5) = 4
// *            howManyBits(0)  = 1
// *            howManyBits(-1) = 1
// *            howManyBits(0x80000000) = 32
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
  // int x = 0x80000000;
  // int y = 0x7FFFFFFF;
  // int l;
  // int sbx = (x>>31)&1;
  // int sby = (y >> 31)&1;
  // int sbl;
  // l = x + (~y)+ 1;
  // printf("l = %d\n", l);
  // sbl = (l>>31)&1;
  // printf("sbx = %d\nsby = %d\n sbl = %d\n",sbx,sby,sbl);
  // int ans = sbx & (sbx^sby); // either x should be negative and  y should be positive
  // printf("ans1 = %d\n", ans);
  // ans = ans |((!(sbx^sby))&&sbl); // or x and y are of same sign and l is negative
  // printf("ans2 = %d\n", ans);
  // int x  = 0x80000000;
  // int sbx = (x>>31)&1;
  // int y = (~x)+1; // negative of x
  // int sby = (y>>31)&1;

  // & ~1; //all 1's if x == 0
  // int l = (~(sbx^sby)) &(sbx^1);
  // int l = 0x80000000 - 1;
  // // l = l>>31;
  // int sbx = l>>31; // if x is negative, all bits are 1, the number is -1. else all bits are zero - the number is zeros
  // int absX = (l^sbx )+(sbx&1);
  // printf("absl = %d\n", absX);
  int x = 0x7ffffff1;
  int sbx = x>>31; // if x is negative, all bits are 1, the number is -1. else all bits are zero - the number is zeros
  int absX =  (x^sbx )+(sbx&1); //gives the absolute value of x;
  int isINTmin =!((1<<31)^x);
  int negisINTmin = (~isINTmin)+1;
  int msb = 0;
  int curr = 0;
  int ans =0x10;
  //binary search, startung at 16th bits
  //  x>>(ans) == 0 -answer is less than 16
  // != 0 ans - answer is greater than 16, set the 4th bit ;
  int z = x;
  x = absX;
  ans = ((!(x>>ans))<<4)^ ans;
  ans = ans | 0x08;
  ans = ((!(x>>ans))<<3)^ ans;
  ans = ans | 0x04;
  ans = ((!(x>>ans))<<2)^ ans;
  ans = ans | 0x02;
  // printf("%d\n",ans);
  ans = ((!(x>>ans))<<1)^ ans;
  // printf("%d\n",ans);

  ans = ans | 0x01;
  ans = (!(x>>ans))^ ans;
  // ans+=1;
  printf("%d\n",ans);

  ans+=!(z);
  printf("%d\n",ans);

  ans+=(1&!(!(z)));
  printf("%d\n",ans);
// z is nonzero and sign bit is zero i.e. positive numbers will require one extra bit
  ans+= ((!(!(z))) & ((!(z>>31)&1)));
  // if the number is negative and 30th indexed bit or 31st bit or right of MSB bit is 0, then add 1;
  int negone = (~1) + 1;
 ans+=((((z>>(ans))&1) & !(z>>(ans+negone) &1))&(sbx&1));
 // ans=ans+negisINTmin;
    printf("%d\n",ans);
  // int z = 1152966764;
  //
  // ans= (!(!(z)) & (!((z>>31)&1)));
  // printf("%d\n",ans);

  // printf("This should be zero.%d\n",(x>>ans));

  // return ((ans |(!l)));
  return 0;
}
