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
void removeDuplicates(int arr[], int n)
{

	set<int>s(arr, arr+n);
	cout << "\nAfter removing duplicates:\n";
	for (auto it = s.begin(); it != s.end(); ++it)
		cout << *it << ", ";
	cout << '\n';
}

// Function to remove duplicate elements from unsorted array
// Function to remove duplicate elements
void remDup(int arr[], int n)
{

	// Initialise a vector to store the array values
	vector<int> v(arr, arr + n);
	// sorting vector
	sort(v.begin(), v.end());

	// using unique() method to remove duplicates
	auto it = unique(v.begin(), v.end());

	// resize the new vector
	v.resize(distance(v.begin(), it));

	// Print the array with duplicates removed
	cout << "\nAfter removing duplicates:\n";
	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << '\n';
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
//Cylendrically rotate an array by one
void rotate(int arr[], int n)
{
    int x = arr[n-1];
    for(int i=n-1; i>0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = x;
}
