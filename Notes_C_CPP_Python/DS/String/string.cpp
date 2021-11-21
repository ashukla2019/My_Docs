#include <iostream>
using namespace std;

//Swap two strings:
void swap(char *str1, char *str2)
{
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}  

//Get frequency of all chars
void frequency(string str)
{
	map<char , int >m;
      
	for(int i=0; i<str.length();i++)
	{   
        m[str[i]]++;
	}
        
    for(auto it = m.begin(); it!=m.end(); it++)
	{
        cout<<it->first<<" - "<<it->second<<endl;
	}
}

//CPP program to remove duplicate character from character array and print in sorted
void removeDuplicate(string str)
{
    std::vector<char> v(str.begin(), str.end());
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) 
    {
        end = std::remove(it + 1, end, *it);
        
    }
 
    v.erase(end, v.end());
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << ' ';
}
    
// A function to check if a string str is palindrome
void isPalindrome(char str[])
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(str) - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is not a palindrome\n", str);
            return;
        }
    }
    printf("%s is a palindrome\n", str);
}

int main()
{
	char *str1 = "geeks";
    char *str2 = "forgeeks";
    swap(str1, str2);
	return 0;
}
