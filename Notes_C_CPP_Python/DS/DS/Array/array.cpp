#include <iostream>
#include <unordered_map>
using namespace std;

// Function to find the element occurring odd number of times 
// XOR of all elements gives us odd occurring element: xor will return true if both digits are different.
// a ^ a = 0
// b ^ b = 0
// a ^ 0 = a
// b ^ 0 = b

//expression: a ^ b ^ a ^ b ^ a = a^a =0 and b^b =0 now 0^a = a means if any number is odd time will not be zero...
int getOddOccurrence(int ar[], int ar_size) 
{ 
    int res = 0;  
    for (int i = 0; i < ar_size; i++)      
        res = res ^ ar[i]; 
      
    return res; 
} 

// Function to remove duplicate elements from sorted array
// This function returns new size of modified
// array. Time Complexity : O(n), Auxiliary Space : O(1)
int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
    {
        return n;
    }

    // To store index of next unique element
    int j = 0;

     // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i=1; i < n-1; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    return j+1;
}


// Function to remove duplicate elements from unsorted array
vector<int> removeDuplicate(int A[], int N) 
{
    vector<int>v;
    unordered_set<int>s;
    for(int i=0;i<N;i++)
    {
		if(s.find(A[i])==s.end())
        {
			s.insert(A[i]);
            v.push_back(A[i]);
        }
    }
    return v;
}
  
// Function to get the missing number
int getMissingNo(int a[], int n)
{
 
    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}

//An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For ////example //int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2
/*C++ Function to print leaders in an array */
void printLeaders(int arr[], int size) 
{ 
    int max_from_right =  arr[size-1]; 
  
    /* Rightmost element is always leader */
    cout << max_from_right << " "; 
      
    for (int i = size-2; i >= 0; i--) 
    { 
        if (max_from_right <= arr[i])  
        {            
            max_from_right = arr[i]; 
            cout << max_from_right << " "; 
        } 
    }     
} 
//Reverse array
void reverseArray(int arr[], int n)
{
    int t, i;
    for (i = 0; i < n/2; i++) 
    {
        t = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = t;    
        
    }
}

//Majority Element: A majority element in an array A[] of size n is an element that appears more than n/2 times
void findMajority(int arr[], int size)
{
    unordered_map<int, int> m;
    for(int i = 0; i < size; i++)
        m[arr[i]]++;
    int count = 0;
    for(auto i : m)
    {
        if(i.second > size / 2)
        {
            count =1;
            cout << "Majority found :- " << i.first<<endl;
            break;
        }
    }
    if(count == 0)
        cout << "No Majority element" << endl;
}


//C function to find maximum in arr[] of size n
int largest(int arr[], int n) {
    int i;

    // Initialize maximum element
    int max = arr[0];

    // Traverse array elements from second and
    // compare every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max) 
			max = arr[i];

    return max;
}
//You are given an array arr[], you have to re-construct an array arr[].
//The values in arr[] are obtained by doing Xor of consecutive elements in the array.
int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    for(int i =0; i<n-1; i++)
    {
        arr[i] = arr[i]^arr[i+1];
    }
    return arr;
    
}
//Cylindrically rotate an array by one
void rotate(int arr[], int n)
{
    int x = arr[n-1];
    for(int i=n-1; i>0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = x;
}

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
*/
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

//Contains Duplicate: Given an integer array nums, return true if any value appears at least 
//twice in the array, and return false if every element is distinct.
/*Input: nums = [1,2,3,1]
Output: true
*/
bool containsDuplicate(vector<int>& nums) 
{
    set<int>s(nums.begin(), nums.end());
    return (nums.size()>s.size());
}

//Given a non-empty array of integers nums, every element appears twice except for one. 
//Find that single one.
/*Input: nums = [2,2,1]
Output: 1*/

int singleNumber(vector<int>& nums) 
{
	int singleNum = 0;
    for(size_t i = 0; i < nums.size(); i++)
    {
		singleNum ^= nums[i];
    }
    return singleNum;

}

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
*/
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

/*Move Zeros: Given an integer array nums, move all 0's to the end of it while maintaining the 
relative order 
of the non-zero elements.
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/
void moveZeroes(vector<int>& nums)
{
	fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
}

/*Rotate image:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
*/
void rotate(vector<vector<int>>& matrix)
{
	int s = matrix.size();
	int temp;

	for (int  i = 0; i < s; i++)
	{
		for (int j = 0; j < i; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}       
	}
	
	for (int i = 0; i < s; i++)
	{
		reverse(matrix[i].begin(), matrix[i].end());
	}
	
}

//Two Sum: Given an array of integers nums and an integer target, return indices of the two numbers such
//that they add up to target.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

vector<int> twoSum(vector<int>& nums, int target) 
{
	unordered_map<int, int> indices;
	for (int i = 0; i < nums.size(); i++) 
	{
		if (indices.find(target - nums[i]) != indices.end())
		{
			return {indices[target - nums[i]], i};
		}
		indices[nums[i]] = i;
	}
	return {};
}

//Armstrong number	
  int getOrder(int n)
    {
        int count = 0;
        while(n)
        {
            count++;
            n = n/10;
        }
        return count;
    }
    string armstrongNumber(int n){
        int num = n;
        int order = getOrder(num);
        int sum =0;
        while(num)
        {
            int digit = num%10;
            sum = sum + pow(digit, order);
            num = num/10;
        }
        return(sum == n ? "Yes": "No");
     
    }	
