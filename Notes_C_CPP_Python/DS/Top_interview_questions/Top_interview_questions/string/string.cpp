//Reverse String: 
/*Write a function that reverses a string. The input string is given as an array of characters s.
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/
void reverseString(vector<char>& s) 
{
	int n = s.size();
	for(int i=0; i<n/2; i++)
	{
		char temp = s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = temp;
	}
}

/*Reverse Integer:Given a signed 32-bit integer x, return x with 
//its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer 
//range [-231, 231 - 1], then return 0.
/*
Input: x = 123
Output: 321
*/
int reverse(int x)
{
	long result = 0;
	while(x != 0)
	{
		result = result*10 + x % 10;
		x /= 10;
	}
	return (result > INT_MAX || result < INT_MIN)? 0 : result;
}


//First unique character:
/*Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.
*/
//Input: s = "leetcode"
//Output: 0
int firstUniqChar(string s) 
{
   int count[26] = {0};
   
   for(char c: s)
   {
	   count[c-'a'] += 1;
   }
   for(int i=0; i<s.length(); i++)
   {
	   if(count[s[i] - 'a'] == 1)
	   {
		   return i;
	   }
	   
   }
	return -1;
	
}

//Valid Anagram:Given two strings s and t, return true if t is an anagram of s, and false otherwise.
/*An anagram of a string is another string that contains the same characters, only the order of 
characters can be different. For example, “abcd” and “dabc” are an anagram of each other.
*/
bool isAnagram(string s, string t) 
{
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t; 
}

//Valid Palindrome:
/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/
bool isPalindrome(string s) 
{
	int start=0, end=s.length()-1;
	while(start<end) 
	{
		if (!isalnum(s[start]))
		{
			start++;
		}
		else if (!isalnum(s[end])) 
		{
			end--;
		}
		else 
		{
			if (tolower(s[start++])!=tolower(s[end--])) 
			{
				return false;
			}
		}
	}
	return true;
}


//Implement strstr:
/*Input: haystack = "hello", needle = "ll"
Output: 2
*/
int strStr(string haystack, string needle) 
 {
	int m = haystack.size(), n = needle.size();
	for (int i = 0; i <= m - n; i++) 
	{
		int j = 0;
		for (; j < n; j++)
		{
			if (haystack[i + j] != needle[j]) 
			{
				break;
			}
		}
		if (j == n) 
		{
			return i;
		}
	}
	return -1;
}

//longest common prefix:
Input: strs = ["flower","flow","flight"]
Output: "fl"

string longestCommonPrefix(vector<string>& strs) 
{
	int n =strs.size();
	string ans; 
	sort(strs.begin(), strs.end());
	string a = strs[0];
	string b = strs[n-1];
	for(int i =0; i< a.size(); i++){
		if(a[i] == b[i]){
			ans += a[i];
		}else break;
	}
	return ans;
}
};
