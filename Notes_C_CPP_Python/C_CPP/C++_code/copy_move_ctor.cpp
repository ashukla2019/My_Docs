#include <iostream> 
#include <vector>
#include <vector> 
using namespace std;

class A 
{ 
    int *ptr;
public:
	//Conversion constructor
    A(int x)
    { 
        cout <<"Calling conversion constructor"<<endl; 
        ptr = new int; 
        *ptr = x;
    }
	//Copy Constructor:copy of object is created
    A( const A & obj)
    { 
        this->ptr = new int;
        *ptr = *(obj.ptr); // Deep copying
        cout <<"Calling Copy constructor"<<endl;
    }
	// Move ctor: It will simply shift the resources of rvalue to lvalue without creating a copy.
    A ( A && obj)
    {
        cout <<"Calling Move constructor"<<endl; 
        this->ptr = obj.ptr;
        obj.ptr = NULL;
    }
	//Assignment operator
    A& operator=( const A & obj)
    { 
        this->ptr = new int;
        *ptr = *(obj.ptr); 
        cout <<"Assignment operator"<<endl;
		return *this;
    }
	//Move Assignment operator
    A& operator= ( A && obj)
    {
        cout <<"Calling Move assignment operator"<<endl; 
        this->ptr = obj.ptr;
        obj.ptr = NULL;
		return *this;
    }
    // Destructor
    ~A()
    { 
       
        cout<<"Calling Destructor"<<endl;
        delete ptr;
    }
        
    void display()
    {
        cout<<"value is:"<<*ptr<<endl;
            
    }
};

A fun( A a1)
{
    return a1;
}

int main()
{
    A a1(10); //calling conversion constructor//
    A a2 = fun(a1);
    //vector <A> vec;
    //vec.push_back(A(10));
    return 0;
    
}
