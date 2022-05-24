#include<iostream>
using namespace std;

#define MAX 5

class myVector
{
private:
	int arr[MAX];
	int top;
public:
	myVector():top(-1){}
	void push_back(int item)
	{
		arr[++top] = item;
	}
	//subscript operator overloading:
	int operator[](int index)
	{
		return arr[index];
	}
	//Iterator class:
	//complete Name:myVector::Iterator
	//Access specifiers
	//Inner class is friend of outer class(can access provate and protected members)
	class Iterator
	{
		myVector* m_p;
		int index;
		public:
			Iterator(myVector* p, int in):m_p(p), index(in){}
			bool operator !=(Iterator rhs)
			{
				if(this->m_p == rhs.m_p)
				{
					if(this->index == rhs.index)
					{
						return false;
					}
				}
				return true;
			}
			void operator++()
			{
				index++;
			}
			int& operator*()
			{
				return m_p->arr[index];
			}
			Iterator begin()
			{
				return Iterator(this, 0);
			}
			Iterator end()
			{
				return Iterator(this, MAX);
			}
	};
	
};

int main()
{
	myVector vobj;
	for(int i = 0; i< MAX; i++)
	{
		vobj.push_back(i);
	}
	for(int i = 0; i< MAX; i++)
	{
		cout<<"values:"<<vobj[i]<<"\n"; //need to overload of subscript operator
	}
	myVector::Iterator it;
	for( it = vobj.begin(); it != vobj.end(); ++it)
	{
		cout<<*it<<"\n";
	}
	return 0;
}