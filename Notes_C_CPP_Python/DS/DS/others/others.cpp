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

//Move zeroes:
//Given an integer array nums, move all 0's to the end of it while maintaining 
//the relative order of the non-zero elements.
void moveZeroes(vector<int>& nums) 
{
	fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
}





