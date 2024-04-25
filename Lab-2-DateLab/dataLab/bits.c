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
	3. Has unpredictable behavior when shifting an integer by more
	than the word size.
	
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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
that you are allowed to use for your implementation of the function. 
	The max operator count is checked by dlc. Note that '=' is not 
	counted; you may use as many of these as you want without penalty.
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
			/* 
			 * bitAnd - x&y using only ~ and | 
			 *   Example: bitAnd(6, 5) = 4
			 *   Legal ops: ~ |
			 *   Max ops: 8
			 *   Rating: 1
			 */
			int bitAnd(int x, int y) {
			//德摩根律
			return ~(~x | ~y);
		}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	//num = 8 * n
	int num = n << 3;
	return x >> num & 0xff;
	
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	//  `>>` 是算术右移，左侧会补充符号位
	// 题目要求实现逻辑右移，要求左侧补充0
	
	// a = 11..10000..0, 共有n个1
	int a = 1 << 31 >> n << 1;
	// ~a = 00..011111, 共有n个0
	return x >> n & ~a;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	//采用分治的策略
	//将所有位分成32组，一组中只有1位；
	//将相邻两组合为一组，组中的数值为原来两组中的数值相加；
	//重复第2步，直到合成只有1组，组中的数值即为结果。
	//------------------------------
	//开始中每组中的数值即为每组中1的数量，
	//然后将相邻两组中的数值相加的过程就相当于将之前一级的1的数量汇总，
	//不断重复这个过程就可以将1的数量汇总到最后的一个数中。
	int m1, m2, m3, m4, m5;
	m1 = 0x55 + (0x55 << 8); //m1 = 01010101...
	m1 = m1 + (m1 << 16);
	m2 = 0x33 + (0x33 << 8);
	m2 = m2 + (m2 << 16);    //m2 = 00110011...
	m3 = 0x0f + (0x0f << 8); 
	m3 = m3 + (m3 << 16);    //m3 = 0x0f0f0f0f
	m4 = 0xff ;              //m4 = 0x00ff00ff
	m4 = m4 + (m4 << 16);
	m5 = 0xff + (0xff << 8); //m5 = 0x0000ffff
	
	//前面的 + 后面的
	x = (x & m1) + ((x >> 1) & m1); //2bits 为1组
	x = (x & m2) + ((x >> 2) & m2); //4bits
	x = (x & m3) + ((x >> 4) & m3); //8
	x = (x & m4) + ((x >> 8) & m4); //16
	x = (x & m5) + ((x >> 16) & m5);//32
	return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	//这里不用像上一题那样计算数量，只用用`|`来保证有就行了
	int or16, or8, or4, or2, or1;
	or16 = x | x >> 16;
	or8 = or16 | or16 >> 8;
	or4 = or8 | or8 >> 4;
	or2 = or4 | or4 >> 2;
	or1 = or2 | or2 >> 1;
	//`& 0x01`是为了清除31-1位上的字符，`^ 0x01`采用异或取反
	return (or1 & 0x01) ^ 0x01;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	//00...000[1011]
	//<------>所有的0都可以看成符号位
	//11...111[0111]
	//<------>所有的1都可以看成符号位
	int sign = x >> 31 & 1; //sign， 1或者0
	int off = n + ~1 + 1;   //data, 对于n位补码，用n-1个字符保存数据
	                        //这里off表示偏移量，也就是数据的最大长度，值为n - 1
	int pos = !sign & !(x >> off);//正数的情况，移位后正确应该是000..000，错误是000..0001..
	int neg = sign & !~(x >> off);//负数的情况，移位后正确应该是111..111，错误是111..1110..
	return pos | neg;
	
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	/*
	  除法要向0取整，使用移位操作是向下取整，正数无所谓，负数就要修正
	  这里负数也只是部分要修正，下面我们以4位补码举例:
	  1010   -6
	  0101   -6/2 = -3, 此时并不需要修正，
						只要右移移出去的是0，也就是这个数还是2的倍数，直接右移就不需要修正
	  0010   -6/4 = -1, 此时需要修正，右移移出去1
					    这里修正需要“+1”，【但是】这个“+1”是在【除完之后的结果】上“+1”，
					    所以在【原数】上 + 【2^n - 1】, 这样只要后n位不全是0，有1，在加上【2^n - 1】后再移位会自动“+1”
	 */
	
	//00..011..11 = (1 << n) + ~1 + 1)
	//     <---->n个1
	// 后面的(x >> 31)是确保当x为负数时，off才会有值
	int off = ((1 << n) + ~1 + 1) & (x >> 31);
	return (off + x)>> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	/*
	  左边是为了排除0，~0 + 1 = 0, 这里还要 >> 31, 否则~x+1结果为0xfffffff0时return 0
	  右边是通过符号位，符号位是0时!为 0x00000001
	 */
	//(!(x >> 31)) --> 0x80000000, no ~ -->0xfffffffff
	return ((~x + 1) >> 31) & (!(x >> 31));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	/*
	  [x - y +] ->yes ->(sx & !sy)
	  [x + y -] ->no
	  [x + y +] ->yes -> y - x >= 0
	  [x - y -] ->yes -> y - x >= 0
	 */
	int sx, sy, res;
	sx = !!(x >> 31);
	sy = !!(y >> 31);
	res = y + ~x + 1; //res = y - x >= 0
	                   // sx和sy同或 //借助上一题，这里不需要排除0
	return (sx & !sy) | (!(sx ^ sy)  & (!(res >> 31)));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	int m1, m2, m3, m4, m5;
	//起初x = 00..0011100110110, 第一个1在第n位 
	x = x | x >> 1; //n、n-1 = 1
	x = x | x >> 2; //n、n-1、n-2、n-3 = 1
	x = x | x >> 4; //n、n-1、n-2、n-3、n-4、n-5、n-6、n-7
	x = x | x >> 8; //...
	x = x | x >> 16;//...
	//x = 00..00111111..111
	//下面数一下有多少个1
	
	
	m1 = 0x55 + (0x55 << 8); //m1 = 01010101...
	m1 = m1 + (m1 << 16);
	m2 = 0x33 + (0x33 << 8);
	m2 = m2 + (m2 << 16);    //m2 = 00110011...
	m3 = 0x0f + (0x0f << 8); 
	m3 = m3 + (m3 << 16);    //m3 = 0x0f0f0f0f
	m4 = 0xff ;              //m4 = 0x00ff00ff
	m4 = m4 + (m4 << 16);
	m5 = 0xff + (0xff << 8); //m5 = 0x0000ffff
	
	x = (x & m1) + ((x >> 1) & m1); //2bits
	x = (x & m2) + ((x >> 2) & m2); //4bits
	x = (x & m3) + ((x >> 4) & m3); //8
	x = (x & m4) + ((x >> 8) & m4); //16
	x = (x & m5) + ((x >> 16) & m5);//32
	
	//x = 00...001 时，logx = 0，所以还要-1
	return x + ~1 + 1;
	
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	/*
	  首先判断uf是否是NAN，
	  通过阶码 == ff和尾数 != 0
	  
	  剩下的符号位取反就行
	  
	 */
	if(((uf & 0x7fffffff) >> 23) == 0xff && uf << 9) return uf;
	return uf ^ 0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	int s;
	int exp;
	int frac;
	int ans;
	int front_zero_cnt;
	int low_9;
	
	//0、两种特殊情况提前判断，这里由于后面要取绝对值全部变成正数，但是0x80000000的绝对值用in没法表示，所以提前判断
	if(x == 0) return 0;
	if(x == 0x80000000) return 0xcf000000; // 1 10011110 ... - 127+31
	
	//1、符号位
	s = x & 0x80000000; 
	
	//2、变成正数
	if(x < 0) x = -x;

	//3、统计从31位到第一个1有多少个0，以此来确定exp
	front_zero_cnt = 0;
	while(!(x & 0x080000000))
	{
		front_zero_cnt++;
		x = x << 1;
	}

	//4、确定exp，-1是减去尾数省略的那个[1.]
	exp = (127 + 32 - front_zero_cnt - 1) << 23;
	x = x <<  1 ; //front_zero_cnt已经去掉了，现在只用去掉尾数省略的那个[1.]

	//5、确定frac
	frac = x >> 9 & 0x007fffff;
	ans = s + exp + frac;
    
	//6、舍入
	low_9 = x & 0x000001ff;  //low_9是没有进入frac的尾数，用其来判断舍入
	if(low_9 > 0x00000100) ans++;
	if((low_9 == 0x00000100) && (ans & 0x1) ) ans++;
	
	return ans;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	int s;
	int exp;
	s = uf & 0x80000000;
	exp = uf & 0x7f800000;
	// +0，-0，无穷，NAN直接判断
	if(uf == 0 ||uf == 0x80000000 || exp == 0x7f800000) return uf;
	if(exp == 0) //非规格化数 ，从尾数左移，把移出来的1放到阶码上
	{
		uf = uf << 1;
		uf = uf + s;
	}
	//规格化数 // 阶码 + 1
	else uf += 0x00800000;
	
	return uf;
}
