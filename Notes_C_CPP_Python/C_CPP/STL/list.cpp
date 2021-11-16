#include<iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	//initialize list with default values
	//list<int>lt(5);
	
	//initialize list with same values
	//list<int>lt(5, 10);
	
	//initialize list with initializer list
	list<int>lt = {10, 20, 30, 40};
	
	//initialize vector with other container
	//string str("Hello");
	//list<char>lt(str.begin(), str.end());
	
	//iterate vector 
	/*for(auto it = lt.begin(); it != lt.end(); it++)
	{
		cout<<"values in list:"<<*it<<endl;
	}*/
	
	/*iterate in reverse order:
	for(auto it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout<<"values in vector:"<<*it<<endl;
	}*/
	
	//Find element:
	/*
	int x = 20;
	auto it = find(lt.begin(), lt.end(), x);
	if(it != lt.end())
	{
		cout<<*it<<endl;
	}
	else
	{
		cout<<"No found"<<endl;
	}
	*/
	//Erase elements: can be removed by direct passing the value.
	//erase element 30 
	int y = 30;
	lt.remove(y);
	for(auto it = lt.begin(); it != lt.end(); it++)
	{
		cout<<"values in list:"<<*it<<endl;
	}
	//Erase elements by position and position range
	//lt.erase(lt.begin()); //by position but do not use like vec.begin()+1
	/*for(auto it = lt.begin(); it != lt.end(); it++)
	{
		cout<<"values in list:"<<*it<<endl;
	}*/
	
	//lt.erase(lt.begin(), lt.begin()); //by position range	
	/*	
	//Remove all occurrences of an element from vector in O(n) complexity:
	//vec.erase(std::remove(vec.begin(), vec.end(), elem), vec.end());
	*/
	return 0;
}