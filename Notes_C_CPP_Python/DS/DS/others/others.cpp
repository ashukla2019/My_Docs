//Number of 1 Bits is also known as hammingWeight:
int hammingWeight(uint32_t n) 
{
	int sum = 0;
	for(int i=0; i<=31; i++)
	{
		int k = 1<<i;
		if(n & k)
		{
			sum += 1;
		}
	}
	return sum;
}

//Hamming Distance:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

int hammingDistance(int x, int y) 
{
   int res =0;
   for(int i=0; i<32; ++i) 
   {
	   if((x &(1<<i) ^ (y &(1<<i))) !=0)
	   {
		   res++;
	   }
   }
	return res;
   
}

/*Reverse Bit:
Reverse bits of a given 32 bits unsigned integer*/
uint32_t reverseBits(uint32_t n) 
{
	int res =0;
	for(int i=31; i>=0; i--)
	{
		res |= (n&1)<<i;
		n >>= 1;
	}
	return res;
}







//Pascal triangle:





/*Valid Parenthesis:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if 
the input string is valid. An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order */
 
bool isValid(string s) 
{
	stack<char> stk;
	for(const auto& c : s)
	{
		switch(c)
		{
			case '{':  stk.push('}'); break;
			case '[':  stk.push(']'); break;
			case '(':  stk.push(')'); break;
			default:
				if(stk.size() == 0 || c != stk.top())
				{
					return false;
				}
				else 
				{
					stk.pop();
				}
		}
	}
	return stk.size() == 0;
}

/*Missing Number:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums */

int missingNumber(vector<int>& nums) 
{
	int n = nums.size();
	int total = (n*(n+1))/2;
	int sum =0;
	for(int i=0; i<n; i++)
	{
		sum += nums[i];
	}
	return (total-sum);
}
