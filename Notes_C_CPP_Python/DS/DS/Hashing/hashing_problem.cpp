/*
Given an array of integers nums and an integer target, return 
indices of the two numbers such that they add up to target.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/
vector<int> twoSum(vector<int>& nums, int target) 
{
	unordered_map<int,int>mp;
	for(int i=0; i<nums.size(); i++)
	{
		if(mp.find(target-nums[i]) != mp.end())
		{
			return {mp[target-nums[i]], i};
		}
		else
		{
			mp[nums[i]] = i;
		}
	}
	return {};
}

//Group of anagram:
//Given an array of strings strs, group the anagrams together. 
//You can return the answer in any order.
/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>>ans;
	//actually, key with value problem: input string will be key and corresponding
	//vector of anagram string will be value.
	map<string, vector<string>>mp;
	for(string s: strs)
	{
		string t = s; 
		sort(t.begin(), t.end());
		mp[t].push_back(s);
	}
	for(auto i: mp)
	{
		ans.push_back(i.second); //map's second will have group of anagram....
	}
	return ans;
}

//Intersection of Two Arrays:
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	unordered_set<int> m(nums1.begin(), nums1.end());
	vector<int> res;
	for (auto a : nums2)
	{
		if (m.count(a)) 
		{
			res.push_back(a);
			m.erase(a);
		}
	}
	return res;
}

//First Unique Character in a String:
/*Given a string s, find the first non-repeating character in it and return
//its index. If it does not exist, return -1.
*/
int firstUniqChar(string s)
{
	unordered_map<char, int> m;
	for (char& c : s) 
	{
		m[c]++;
	}
	for (int i = 0; i < s.size(); i++) 
	{
		if (m[s[i]] == 1) return i;
	}
	return -1;
}

//House rob:
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security systems 
connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.
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

