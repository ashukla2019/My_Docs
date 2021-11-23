/*
Set :
	Set is an associative container which we need to store unique elements.
	It always keeps the elements in sorted order.
	Internally it maintains a balanced binary search tree of elements. Therefore, 
	when we search an element inside the set then it takes only log(n) complexity to search it.
*/

/*    |     set             | unordered_set
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search

/*
prefer set:
•	if you wish to filter multiple identical values
•	if you wish to parse items in a specified order (doing this in vector requires to specifically sort vector).
prefer vector:
•	if you want to keep identical values
•	if you wish to parse items in same order as you pushed them (assuming you don't process the vector order)
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    std::set<std::string> setOfNumbers;
    // Lets insert four elements
    setOfNumbers.insert("first");
    setOfNumbers.insert("second");
    setOfNumbers.insert("third");
    setOfNumbers.insert("first"); //this is duplicate, so will not be added in set.
    // Only 3 elements will be inserted
    std::cout<<"Set Size = "<<setOfNumbers.size()<<std::endl;
    // Iterate through all the elements in a set and display the value.
    
	//search an element in std::set
	// Search for element in set using find member function
     // Search for element in set using find member function
    std::set<std::string>::iterator it = setOfNumbers.find("second");
    if(it != setOfNumbers.end())
        std::cout<<"'first'  found"<<std::endl;
    else
        std::cout<<"'first' not found"<<std::endl;
	
	//iterator  erase (const_iterator position);
	//size_type erase (const value_type& val);
	//iterator  erase (const_iterator first, const_iterator last);
	
    return 0;
}