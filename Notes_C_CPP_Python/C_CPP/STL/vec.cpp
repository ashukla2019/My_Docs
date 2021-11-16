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
	
	//iterate vector 
	/*for(auto it = vec.begin(); it != vec.end(); it++)
	{
		cout<<"values in vector:"<<*it<<endl;
	}
	vec.pop_back();
	//iterate in reverse order:
	for(auto it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout<<"values in vector:"<<*it<<endl;
	}*/
	
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
	//Erase elements
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