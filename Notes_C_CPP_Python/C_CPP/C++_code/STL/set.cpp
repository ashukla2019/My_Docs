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

// erasing from set
#include <iostream>
#include <set>

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator it;

  // insert some values:
  for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

  it = myset.begin();
  ++it;                                         // "it" points now to 20

  myset.erase (it); //erase by position

  myset.erase (40); //erase value from set.

  it = myset.find (60);
  myset.erase (it, myset.end()); //erase values using range....

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}