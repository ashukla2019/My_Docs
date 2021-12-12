#include <iostream>
#include <unordered_map>
using namespace std;

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
