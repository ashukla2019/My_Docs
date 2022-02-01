#include <iostream> 
#include <vector>
#include <vector> 
using namespace std;

class A 
{ 
    int *ptr;
public:
    A(int x)
    { 
        cout <<"Calling conversion constructor"<<endl; 
        ptr = new int; 
        *ptr = x;
    }
    A( const A & obj)
    { 
        // Copy Constructor: copy of object is created
        this->ptr = new int;
        *ptr = *(obj.ptr); // Deep copying
        cout <<"Calling Copy constructor"<<endl;
    }
    A ( A && obj)
    {
        // Move constructor: It will simply shift the resources, // 
        //without creating a copy.
        cout <<"Calling Move constructor"<<endl; 
        this->ptr = obj.ptr;
        obj.ptr = NULL;
    }
    
    A operator= ( A && obj)
    {
        // Move constructor: It will simply shift the resources, // 
        //without creating a copy.
        cout <<"Calling Move Assignment"<<endl; 
        //this->ptr = obj.ptr;
        //obj.ptr = NULL;
    }
    
    ~A()
    { 
        // Destructor
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
