//Remove Duplicates from Sorted Array:
/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
each unique element appears only once. The relative order of the elements should be kept the same.

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

//Solution:
int removeDuplicates(vector<int>& nums) 
{
	auto it = unique(nums.begin(), nums.end());
    return distance(nums.begin(),it);  //distance return number of elements b/w two position/iterators
}
*/

//Best Time to Buy and Sell Stock II
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

int maxProfit(vector<int>& prices) 
{
    int profit = 0;
    if(prices.size() == 0)
    {
		return 0;
    }
    else
    {
		for(int i =0; i<prices.size()-1; i++)
        {
			if(prices[i+1]>prices[i])
            {
				profit = profit + (prices[i+1]-prices[i]);
            }
        }
    }
    return profit;
*/	

//Rotate Array:Given an array, rotate the array to the right by k steps, where k is non-negative.
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]	

 void rotate(vector<int>& nums, int k) 
 {
    vector<int>res = nums;
    int n = nums.size();
    for(int i=0;i<nums.size();i++)
	{
        nums[(i+k)%n]=res[i];
    }
*/	

//Contains Duplicate: Given an integer array nums, return true if any value appears at least 
//twice in the array, and return false if every element is distinct.
/*Input: nums = [1,2,3,1]
Output: true

bool containsDuplicate(vector<int>& nums) 
{
    set<int>s(nums.begin(), nums.end());
    return (nums.size()>s.size());
}
*/

//Given a non-empty array of integers nums, every element appears twice except for one. 
//Find that single one.
/*Input: nums = [2,2,1]
Output: 1
int singleNumber(vector<int>& nums) 
{
	int singleNum = 0;
    for(size_t i = 0; i < nums.size(); i++)
    {
		singleNum ^= nums[i];
    }
    return singleNum;

}
*/

//Intersection of Two Arrays II:
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and 
you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]



//Plus one
/*You are given a large integer represented as an integer array digits, where each digits[i] is 
the ith digit of the integer. The digits are ordered from most significant to least 
significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

vector<int> plusOne(vector<int>& digits) 
{
   for(int i=digits.size()-1;i>=0;i--)
   {
		if(digits[i]==9)
		{
			digits[i]=0;
		}
		else
		{
			digits[i]++;
			return digits;
		}
	}
	digits[0]=1;
	digits.push_back(0);
	return digits;
}

//Move Zeros: Given an integer array nums, move all 0's to the end of it while maintaining the relative order 
of the non-zero elements.
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

void moveZeroes(vector<int>& nums)
{
	fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
}
