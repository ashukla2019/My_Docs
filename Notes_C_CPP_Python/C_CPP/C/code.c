//Fibonacci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 
//Fn = Fn-1 + Fn-2
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for(i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}

//Swap two nibbles in a byte:
int swapNibbles(int x)
{
    return ( (x & 0x0F) << 4 | (x & 0xF0) >> 4 );
}

//Bit manipulations:
//set a bit in the number ‘num’: 
// First step is shift '1' by position, second step is bitwise OR with num
void set(int & num,int pos)
{
	num = num |(1 << pos-1);
}
int main()
{
	int num = 4, pos = 1;
	set(num, pos);
	cout << (int)(num) << endl;
	return 0;
}

//Unset/clear a bit at n’th position in the number ‘num’ : 
//First step is shift '1' by position, and take bitwise not of it then bitwise OR with num
void unset(int &num,int pos)
{
	num = num &(~(1 << pos-1));
}
int main()
{
	int num = 7;
	int pos = 1;
	unset(num, pos);
	cout << num << endl;
	return 0;
}

//Toggling a bit at nth position:
//Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1) previously.
// First step is to shift 1,Second step is to XOR with given number
void toggle(int &num, int pos)
{
	num ^= (1 << pos-1);
}
int main()
{
	int num = 4;
	int pos = 1;
	toggle(num, pos);
	cout << num << endl;
	return 0;
}

//convert number into bits
void convertBin(int num)
{
	// Size of an integer is assumed to be 32 bits 
    for (int i = 31; i >= 0; i--) { 
        int k = 1 << i; 
        if (k & num) 
            std::cout << "1"; 
        else
            std::cout << "0"; 
    } 
}
int main(int argc, char* argv[])
{
	
	convertBin(3);
	return 0;
}

//Checking if bit at nth position is set or unset: 
//Left shift ‘1’ to given position and then ‘AND'(‘&’)
bool at_position(int num,int pos)
{
	bool bit = num & (1<<pos-1);
	return bit;
}
int main()
{
	int num = 5;
	int pos = 0;
	bool bit = at_position(num, pos);
	cout << bit << endl;
	return 0;
}

//Inverting every bit of a number/1’s complement:
//If we want to invert every bit of a number 
//i.e change bit ‘0’ to ‘1’ and bit ‘1’ to ‘0’.We can do this with the help of ‘~’ operator.
int main()
{
	int num = 4;
	cout << (~num);
	return 0;
}

//Check if number is power of 2:
bool isPowerOfTwo (int x)
{
/* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}

//Swap two numbers:
void swap(int a, int b)
{
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}
int main()
{
	swap(4,5);
	return 0;
}




