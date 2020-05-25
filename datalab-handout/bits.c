/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
// #include <stdio.h>
//1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~((~(x&~y)) & (~(y&~x)));
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int y = x + x + 2;
  return !y & !(!(~x));
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // int y = (x & 0xAA );
  // x = x >> 8;
  // y += x & 0xAA;
  // x = x>> 8;
  // y+= x &0xAA;
  // x = x>>8;
  // y+=x & 0xAA;
  int y = 0xAA;
  int z = (y<<24) | (y<<16) | (y<<8) |y;

  return !((z&x)^z);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  int y =(~x)+1;
  // printf()
  return y;
}
//3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int y = !(x>>8);//checking first 24 bits are zero
  int w = !((x& 0xF0)^0x30);// checking 25th and 26th bit from MSB side is zero.
  // w also checks whether 27th and 28th bit both are 1 (0011 - 3)
  int m = x & 0xF; // taking
  int h = !(m >>3); // either number is less than 8
  int z  = !(m & 0x6); // or number is less than or equal to 9

  return y & w & (h|z);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int l;
  x = !(!x); // if x us non zero , then it is replaced with 1
  l = ~(~x+1); // l is all 1's if x is 0 and l is all 0's if x is 1

// x is zero => l is all 1 's => z should be the output
// x is one => l is all zeros => y should be the output.
  return ((l&z)|((~l) &y));
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int l;
  int sbx = (x>>31)&1;
  int sby = (y >> 31)&1;
  int sbl;
  int ans;
  l = x + (~y)+ 1;
  // printf("l = %d\n", l);
  sbl = (l>>31)&1;
  ans = sbx & (sbx^sby); // either x should be negative and  y should be positive
  ans = ans |((!(sbx^sby))&sbl); // or x and y are of same sign and l is negative
  return ((ans |(!l)));
}
//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  // int ans = 1;
  // int t = (~(~x+1));
  int sbx = (x>>31)&1;
  int y = (~x)+1; // negative of x
  int sby = (y>>31)&1;

  // & ~1; //all 1's if x == 0
  return (~(sbx^sby)) &(sbx^1);

}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // convet number to positive;
  // int x =0x7fffffff;
  // int x = 0x7ffffff1;
  int sbx = x>>31; // if x is negative, all bits are 1, the number is -1. else all bits are zero - the number is zeros
  int absX =  (x^sbx )+(sbx&1); //gives the absolute value of x;
  // int isINTmin =!((1<<31)^x);
  // int negisINTmin = (~isINTmin)+1;
  // int msb = 0;
  // int curr = 0;
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
  // printf("%d\n",ans);

  ans+=!(z);
  // printf("%d\n",ans);

  ans+=(1&!(!(z)));
  // printf("%d\n",ans);
// z is nonzero and sign bit is zero i.e. positive numbers will require one extra bit
  ans+= ((!(!(z))) & ((!(z>>31)&1)));
  // if the number is negative and 30th indexed bit or 31st bit or right of MSB bit is 0, then add 1;
  int negone = (~1) + 1;
 ans+=((((z>>(ans))&1) & !(z>>(ans+negone) &1))&(sbx&1));
 return ans;



//   int sbx = x>>31; // if x is negative, all bits are 1, the number is -1. else all bits are zero - the number is zeros
//   int absX =  (x^sbx )+(sbx&1); //gives the absolute value of x;
//   // int isINTmin =!(absX^x);
//   // int msb = 0;
//   // int curr = 0;
//   int z = x;
//   int ans =0x10;//binary search, startung at 16th bits
//   //  x>>(ans) == 0 -answer is less than 16
//   // != 0 ans - answer is greater than 16, set the 4th bit ;
//   x = absX;
//   ans = ((!(x>>ans))<<4)^ ans;
//   ans = ans | 0x08;
//   ans = ((!(x>>ans))<<3)^ ans;
//   ans = ans | 0x04;
//   ans = ((!(x>>ans))<<2)^ ans;
//   ans = ans | 0x02;
//   ans = ((!(x>>ans))<<1)^ ans;
//   ans = ans | 0x01;
//   ans = (!(x>>ans))^ ans;
//   // answer stores the index, so add 1
//   ans+=(1&!(!(x)));
// // add one to answer only for positive numbers to account for 2's complement
// // nothing is added if x is already INT_MIN
//   // ans+= (!(x>>ans)&1);
//   ans+= (!(!(z))) & (!((z>>31)&1)));
//
//   // ans+= ((z)& !((z>>31)&1));
//   ans+=!(z);

}
//float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
