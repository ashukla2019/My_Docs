/*
Map:  is used to store key-value pairs. Multimap is nothing different than a normal map except the fact that in a multimap mutiple values can have the same key.
	Map is an associative container that is used to store key-value pair of elements with unique keys.
	It always keeps the inserted pairs in sorted order based on the key.
	Internally it maintains a balanced binary search tree to store keys. Therefore, 
	when searching key inside the map takes only log(n) complexity.
	We cannot modify the key of any inserted pair in map.
	We can modify the value associated with a key in any inserted pair in map.  
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
	/*
	map<char,int> first;
  
	//initializing
	first['a']=10;
	first['b']=20;
	first['c']=30;
	first['d']=40;
    */
	map<char,int> first = {{'a', 10}, {'b', 20}};
	for(auto it=first.begin(); it!=first.end(); ++it)
	{
		cout << it->first << " => " << it->second << '\n';
	}
	
	//Inserting data with insert member function.

	first.insert(make_pair('e', 50));
	first.insert(make_pair('f', 60));
	
	first.insert(make_pair('g', 70));
	first.insert(make_pair('h', 80));
	
	for(auto it=first.begin(); it!=first.end(); ++it)
	{
		cout << it->first << " => " << it->second << '\n';
	}
	
	//can access element using .at or []
	//cout<<first.at('a')<<endl;
	
	// function to erase given keys
    first.erase('e');
    first.erase('f');

	// map::erase(iterator position)
	// function to erase given position
    auto it = first.find('a');
    first.erase(it);
		
	// erasing a given range:
	// the position where the element is
    auto it1 = first.find('g');
    auto it2 = first.find('h');
    first.erase(it1, it2);
	return 0;
	
}
	
