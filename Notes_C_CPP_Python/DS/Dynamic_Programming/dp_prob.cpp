//Fibnoci series: 0,1,1,2,3,5,8,13,21.... T(n) = O(n)
int fib(int n)
{
	if(n<=1)
		return n;
	int result;
	int prev1 =0, prev2 =1;
	for(int i=2;i<=n;++i)
	{
		result = prev1+prev2;
		prev1 = prev2;
		prev2 = result;
	}
	return result;
}

//Maximum sub array: Kadane's algo:
/*
Given an integer array nums, find the contiguous subarray (containing at least one 
number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

int maxSubArray(vector<int>& nums) 
{
	int globalMaxSum = nums[0], currMaxSum = nums[0];
	for (int i = 1; i < nums.size(); i++) 
	{
		currMaxSum = max(currMaxSum + nums[i], nums[i]);
		globalMaxSum = max(globalMaxSum, currMaxSum);
	}
	return globalMaxSum;
}

//House rob-1:
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security systems 
connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.
Input array: [2,7,9,3,1]
*/
int rob(vector<int>& nums) 
{ 
	int n = nums.size(), pre = 0, cur = 0;
	for (int i = 0; i < n; i++) 
	{
		int temp = max(pre + nums[i], cur);
		pre = cur;
		cur = temp;
	 }
	return cur;
}

//House rob-2:
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are 
arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically
contact the police if two adjacent houses were broken into on the same night.
Input array: [1,2,3,1]
*/
int robOriginal(vector<int>& nums) 
{ 
	int n = nums.size(), pre = 0, cur = 0;
	for (int i = 0; i < n; i++) 
	{
		int temp = max(pre + nums[i], cur);
		pre = cur;
		cur = temp;
	 }
	return cur;
}

int rob(vector<int>& nums) 
{
	if(nums.empty()) return 0;
	if(nums.size() == 1) return nums[0];

	vector<int> numsA(nums.begin() + 1, nums.end());
	vector<int> numsB(nums.begin(), nums.end()-1);

	return max(robOriginal(numsA), robOriginal(numsB));
}

//Best Time to Buy and Sell Stock -1
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share 
of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/
int maxProfit(vector<int>& prices) 
{
	int maxProfit = 0;
	int minPrice = INT_MAX;
	//Time complexity:O(n), space complexity:(1)
	for(int i=0; i<prices.size(); i++)
	{
		minPrice = min(minPrice, prices[i]);
		maxProfit = max(maxProfit, prices[i]-minPrice);
	}
	return maxProfit;
	
}