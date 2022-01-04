/*
1.) Ordered Collection:
In std::vector all elements will remain in same order in which they are inserted.
2.) Provides random access:
Indexing is very fast in std::vector using opeartor [], just like arrays.
3.) Performance:
It Performs better if insertion and deletion is in end only and gives worst performance if insertion/deletion is at middle or at starting of vector.
4.) Contains Copy:
It always stores copy of the object not the same reference. So, if you are adding objects of user defined classes then you should define copy constructor and assignment operator in your class.
*/

/*
vector::push_back(): This modifier pushes the elements from the back.
vector::insert(): For inserting new items to a vector at a specified location.
vector::pop_back(): This modifier removes the vector elements from the back.
vector::erase(): It is used for removing a range of elements from the specified location.
vector::clear(): It removes all the vector elements.
*/

#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	//initialize vector with default values
	//vector<int>vec(5);
	
	//initialize vector with same values
	//vector<int>vec(5, 10);
	
	//initialize vector with initializer list
	vector<int>vec = {10, 20, 30, 40,20};
	
	//initialize vector with other container
	//string str("Hello");
	//vector<char>vec(str.begin(), str.end());
	
	//insert value using push_back:
	//vec.push_back(50);
	
	//vec.pop_back();
	//iterate in reverse order:
	/*for(auto it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout<<"values in vector:"<<*it<<endl;
	}*/
	//Insert element in vector:
	//vec.insert(vec.begin(), 7);
	//Find element:
	/*
	int x = 20;
	auto it = find(vec.begin(), vec.end(), x);
	if(it != vec.end())
	{
		cout<<*it<<endl;
	}
	else
	{
		cout<<"No found"<<endl;
	}
	*/
	//erase element 30 
	/*int y = 30;
	auto it = find(vec.begin(), vec.end(), y);
	if(it != vec.end())
	{
		vec.erase(it);
	}
	else
	{
		cout<<"No found"<<endl;
	}
	for(auto it = vec.begin(); it != vec.end(); it++)
	{
		cout<<"values in vector:"<<*it<<endl;
	}*/
	//Erase elements by position and position range
	//vec.erase(vec.begin()+1); by position
	//vec.erase(vec.begin(), vec.begin()+2); by position range	
	//Remove all occurrences of an element from vector in O(n) complexity:
	//int elem = 20;
	//vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());
	/*for(auto it = vec.begin(); it != vec.end(); it++)
	{
		cout<<"values in vector:"<<*it<<endl;
	}*/
	return 0;
}