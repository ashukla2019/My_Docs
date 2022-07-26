//Intersection of Two Arrays II:
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and 
you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
*/

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin());
	nums1.erase(it, nums1.end());
	return nums1;
}