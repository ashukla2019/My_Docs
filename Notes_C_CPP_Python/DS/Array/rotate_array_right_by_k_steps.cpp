//Rotate Array:Given an array, rotate the array to the right by k steps, where k is non-negative.
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]	
*/
void rotate(vector<int>& nums, int k) 
{
	vector<int>res = nums;
	int n = nums.size();
	for(int i=0;i<nums.size();i++)
	{
		nums[(i+k)%n]=res[i];
	}
}