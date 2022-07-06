#include<iosteam>
using namespace std;
//Problem without Virtual function:
class A
{	public:
	void fun1()
	{
		cout<<"A::fun1 is called"<<endl;
	}
};
class B: public A
{
	public:
	void fun1()
	{
		cout<<"B::fun1 is called"<<endl;
	}
	void fun2()
	{
	cout<<"B::fun2 is called"<<endl;
	}
};

int main()
{
	A*p, a1;
	B b1;
	p = &b1; //This will be executed at run time. compiler does not know if p is holding address of object of A/B.
	b1.fun1(); //EB: compile time binding.
	p->fun1(); //EB: compile time binding. compiler will check type of p which is of class A type. It will call class A function. Ideally we want to call function of class B, since we passed object of class B.
	return 0;  
}
//Virtual function concept can be implemented only using pointers. Because pointer may hold address of
//object of any class. Which is evaluated at run time. If we declare Class A's function to virtual.
//Compiler will not do early binding. It will be then late binding.

#include<iosteam>
using namespace std;

class A
{	public:
	virtual void fun1()
	{
		cout<<"A::fun1 is called"<<endl;
	}
};
class B: public A
{
	public:
	void fun1()
	{
		cout<<"B::fun1 is called"<<endl;
	}
	void fun2()
	{
	cout<<"B::fun2 is called"<<endl;
	}
};

int main()
{
	A*p, a1;
	B b1;
	p = &b1;   //This will be executed at run time. compiler does not know if p is holding address of object of A/B.
	b1.fun1(); //EB: compile time binding.
	p->fun1(); //LB: Run time binding. 
	return 0;  
}
