#include<iostream>
using namespace std;
class A
{
private:	
	int x;
public:
	A():x(10){}
	friend ostream& operator<<(ostream& out, const A& a)
	{
		out<<a.x;
		out<<"my operator << is called";
		return out;
	}
	friend istream& operator>>(istream& is, A& a)
	{
		is >> a.x;
		return is;
	}

	
};
int main()
{
	A a;
	//cout<<a;
	cin >> a;
	return 0;
}