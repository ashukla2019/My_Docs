//Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:
Input:
N = 5
A[] = {1,2,3,5}
Output: 4

int MissingNumber(vector<int>& array, int n) {
        int total =0;
        for(int i=0; i<array.size(); i++)
        {
            total += array[i];
        }
        return (n*(n+1)/2 - total);
    }
    

/*Fizz Buzz:

Given an integer n, return a string array answer (1-indexed) where:
answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.

Input: n = 3
Output: ["1","2","Fizz"]
*/

vector<string> fizzBuzz(int n)
{
	vector<string>s;
	for(int i=1; i<=n; i++)
	{
		if(i%3 ==0 && i%5 ==0)
		{
			s.push_back("FizzBuzz");
		}
		else if(i%5 == 0)
		{
			s.push_back("Buzz");
		}
		else if(i%3 == 0)
		{
			s.push_back("Fizz");
		}
		else
		{
			s.push_back(to_string(i));
		}
	}
	return s;
}

/*Count primes:
Given an integer n, return the number of prime numbers that are strictly less than n.
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/



/*power of three*/
bool isPowerOfThree(int n) 
{
	while(n >=3)
	{
		if(n%3 !=0)
		{
			return false;
		}
		n = n/3;
	}
	return n==1;
}

/*Roman to integer:
