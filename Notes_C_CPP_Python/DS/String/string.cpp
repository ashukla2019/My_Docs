#include <iostream>
#include <unordered_map>
using namespace std;

/*
//String class:
getline():- This function is used to store a stream of characters as entered by the user in the 
object memory.
getline(cin,str);
push_back():- This function is used to input a character at the end of the string.
pop_back():- Introduced from C++11(for strings), this function is used to delete the last character 
from the string.
length():-This function finds the length of the string.
*/

/*
Tokenize a string in C++
Using stringstream: A stringstream associates a string object with a stream allowing you to read 
from the string as if it were a stream.
*/
// Tokenizing a string using stringstream
#include <bits/stdc++.h>

int main()
{
	
	string line = "GeeksForGeeks is a must try";
	
	// Vector of string to save tokens
	vector <string> tokens;
	
	// stringstream class check1
	stringstream check1(line);
	
	string intermediate;
	
	// Tokenizing w.r.t. space ' '
	while(getline(check1, intermediate, ' ')) //or while(check1 >> intermediate)
	{
		tokens.push_back(intermediate);
	}
	
	// Printing the token vector
	for(int i = 0; i < tokens.size(); i++)
		cout << tokens[i] << '\n';
}

//Tokenizing a string using stringstream Using strtok():
int main()
{
	char str[] = "Geeks-for-Geeks";

	//Returns first token
	char *token = strtok(str, "-");

	//Keep printing tokens while one of the delimiters present in str[].
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "-");
	}

	return 0;
}

/*
strrchr() function:
In C++, strrchr() is a predefined function used for string handling. cstring is the header file required
for string functions. This function returns a pointer to the last occurrence of a character in a string. 
*/

/*String stream applications:
// CPP program to count words in a string using stringstream.
#include <bits/stdc++.h>

int countWords(string str)
{
	// breaking input into word using string stream
	stringstream s(str); // Used for breaking words
	string word; // to store individual words

	int count = 0;
	while (s >> word)
		count++;
	return count;
}

// Driver code
int main()
{
	string s = "geeks for geeks geeks "
			"contribution placements";
	cout << " Number of words are: " << countWords(s);
	return 0;
}

// CPP program to demonstrate use of stringstream to count frequencies of words.

void printFrequency(string st)
{
	// each word it mapped to it's frequency
	map<string, int> FW;
	stringstream ss(st); // Used for breaking words
	string Word; // To store individual words

	while (ss >> Word)
		FW[Word]++;

	map<string, int>::iterator m;
	for (m = FW.begin(); m != FW.end(); m++)
		cout << m->first << " -> "
			<< m->second << "\n";
}

// Driver code
int main()
{
	string s = "Geeks For Geeks Ide";
	printFrequency(s);
	return 0;
}

/*
// Function to remove spaces
string removeSpaces(string str)
{
	stringstream ss(str);
	string temp;
    str = "";
    while(ss >> temp)
    {
        str = str + temp;
    }
	return str;
}

// Driver function
int main()
{
	// Sample Inputs
	string s = "This is a test";
	cout << removeSpaces(s) << endl;
*/

/*
//Find words greater than k length....
void findWords(string str, int K)
{
    string word;
      
    // using stringstream to break
    // the string into tokens
    stringstream ss(str); 
      
    int count = 0;
    while (ss >> word) { // reading words
        if (word.size() > K) {
            cout << word << " ";
            count++;
        }
    }
}

*/

//Swap two strings:
void swap(char *str1, char *str2)
{
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}  

//Get frequency of all chars in given string
void printFrequency(string str)
{
	// Define an unordered_map
	unordered_map<char, int> M;

	// Traverse string str check if
	// current character is present
	// or not
	for (int i = 0; str[i]; i++)
	{
		// If the current characters is not found then insert current characters with
		// frequency 1
		if (M.find(str[i]) == M.end())
		{
			M.insert(make_pair(str[i], 1));
			
		}

		// Else update the frequency
		else
		{
			M[str[i]]++;
		}
	}

	// Traverse the map to print the
	// frequency
	for (auto& it : M) 
	{
		cout << it.first << ' ' << it.second << '\n';
	}
}

int findstrlen(const char *str)
{
	int len=0;
	while(*str)
	{
		len++;
		str++;
	}
	return len;
}
char* mystrcat(char* dest, const char*src)
{
	int i = 0, j =0;
	int len = findstrlen(dest);
	while(dest[i] != '\0')
	{
	printf("string before concating is %c\n", dest[i]);
	i++;
	}
	while(src[j] != '\0')
	{
	dest[i] = src[j];
	i++;
	j++;
	}
	dest[i] = '\0';
	printf("concanated string is %s\n", dest);
	return dest;
}
// Function to implement strcmp function
int strcmp(const char *X, const char *Y)
{
	while(*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
		break;
		// move to next pair of characters
		X++;
		Y++;
	}
	// return the ASCII difference after converting char* to unsigned char*
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}
char* mystrcpy(char* dest, const char* src)
{
	int i = 0;
	while(src[i] != '\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return dest;
}
char *reverseString(char *str)
{
	char temp;
	int len = findstrlen(str);
	ptr = (char*)malloc(sizeof(char)*len);
	for(int i=0; i< len/2 ; i++)
	{
		temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
	printf("reverse string is %s\n", str);
	return str;
}

/*
//Parse string and return if string contains int/float/alphanumeric

enum type
{
	inttype,
	floattype,
	alphanumeric
};

int checkStringType(char* str)
{
	int length = strlen(str);
	int type;
	for(int i = 0; i< length; i++)
	{
		if(str[i] == '.')
		{
			type = floattype;
			break;
		}
		else if(!isdigit(str[i]))
		{
			type = alphanumeric;
			break;
		}
		else
		{
			type = inttype;
		}
	}
	return type;
}

// Driver Code 
int main() 
{ 
	char str[] = "121";
	cout<<"type of string is:"<<checkStringType(str)<<endl;
	return 0; 
} 

*/


// Function to remove all occurrences of given string
string removeCharacters(string S, char c)
{
  
    S.erase(remove(S.begin(), S.end(), c),S.end());
  
    return S;
}
    
// A function to check if a string str is palindrome
string isPalindrome(string S)
{
	int length = S.length();
    // Iterate over the range [0, N/2]
    for (int i = 0; i < length / 2; i++) 
	{
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[length - i - 1]) 
		{
            // Return No
            return "No";
        }
    }
    // Return "Yes"
    return "Yes";
}

int main()
{
	char *str1 = "geeks";
    char *str2 = "forgeeks";
    swap(str1, str2);
	return 0;
}


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

//Reverse word in given string:
Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i

string reverseWords(string S) 
{ 
 istringstream iss(S);
 string rtr = "";
 string token;
 while (std::getline(iss, token, '.')) 
 {
     if (!token.empty())
     {
	rtr = token + "." + rtr;

    }

}
rtr.pop_back();
return rtr;
} 
