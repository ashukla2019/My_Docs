/*
***************Rule of Zero: 


***************Rule of three:
The rule of three is also known as the Law of Big Three or The Big Three and 
prescribes for class that, if a class defines any of the mentioned three then 
it should probably explicitly define all three:

destructor
copy constructor
copy assignment constructor
These three are special member functions of class. If none of them is explicitly
defined by the programmer, then the compiler provides implicit versions. 
If any one of the above is explicitly defined that means implicit versions for
the other two must be improper and must be redefined.

This happens because implicitly generated constructors and assignment operators’ 
shallow copy the data members. We require deep copy when class contains pointers 
pointing to dynamically allocated resources.

The default destructors remove the unused objects. When there is no copy 
constructor defined then the destructor will run twice, once for objects that
contain the copy and second for objects from which the data members are copied. 
To avoid this, explicit definition becomes necessary.

**************Rule of Five:
Rule of five is an extension of the rule of three due to the introduction of 
move semantics in C++11. The rule of five is also applied in C++ for resource 
management. This rule potentially eliminates memory leaks and other problems 
in C++ code. The Rule of The Big Five states that if you have to write one of 
the following functions then you have to have a policy for all of them. 
If we have an Object Foo then we can have a FooManager that handles the 
resource Foo. When implementing FooManager, you'll likely all need the
following functions to be implemented:

Destructor: When this manager goes out of scope it should free all the resources 
it was managing.

Assignment operator:If you do not provide one the compiler creates a default 
assignment operator. The default assignment operation is a member-wise copy 
function and does a shallow copy and not a deep copy. This could cause problems
like memory leaks, wrong assignment.

Copy constructor:The compiler-supplied copy constructor does a member-wise copy 
of all the FooManagers attributes. This poses the same problems as the assignment
operator.

Move constructor:Copying objects can be expensive as it involves creating, 
copying and then destroying temporary objects. C++11 introduced the concept
of the r-value reference. An r-value reference can be explicitly bound to 
an r-value. An r-value is an unnamed object. A temporary object, in other words.
This r-value reference can be used in a constructor to create a reference to 
the r-value passed to it.

Move assignment operator:It is useful to only have one resource at a time. 
This resource's ownership can be transferred from one manager to another.
In such cases, you can provide a move assignment operator.
*/

//1) Type Inference(auto and decltype):
//Typeid is an operator which is used where the dynamic type of an object needs
//to be known.

/*
decltype Keyword: It inspects the declared type of an entity or the type of an
expression. ‘auto’ lets you declare a variable with a particular type whereas
decltype lets you extract the type from the variable so decltype is sort of an
operator that evaluates the type of passed expression.

decltype(fun1()) x; //// Data type of x is same as return type of fun1() 
*/

1)Auto: Automatic Type Deduction: It infer the type.
	//Before C++11, the auto keyword was used for storage class.
	//auto is now a sort of placeholder for a type, telling the compiler it has to deduce the actual type 
	//of a variable that is being declared from its initializer. 
	auto i = 42;        // i is an int
	auto l = 42LL;      // l is an long long
	auto p = new foo(); // p is a foo*
	
	auto i = 10+5;
	1) compile time: to fetch the result type of expression(10+5)
	2) run time: to evaluate the expression at run time. we can use decltype
	which will identify at compile time.
	decltype(

	//auto can be used for iterators also.
	vector<int>::iterator it; //old way
	for(auto it = begin(map); it != end(map); ++it)  -->auto it will automatically will take type
	{
	}

	//Function return type deduction is implemented in C++14:
	auto Correct(int i)
	{
	  if (i == 1)
		return i;             // return type deduced as int

	  return Correct(i-1)+i;  // ok to call it now
	}

	//Type deduction with braced initializers (C++14)
	auto A = { 1, 2 }; // std::initializer_list<int>
	auto B = { 3 }; // std::initializer_list<int>
	auto C{ 4 }; // int
	auto D = { 5, 6.7 }; // C3535: cannot deduce type for 'auto' from initializer list'
	
	//Don't use auto: when type conversion is needed...
	
2)Nullptr:To avoid mistakes which might occur when a null pointer gets interpreted as an integral value. 
	void fun(char* s)
	{
		cout<<"inside fun(char*)"<<endl;
	}
	void fun(int x)
	{
		cout<<"inside fun(int)"<<endl;
	}
	int main()
	{
		fun(NULL); //There will be an error to find matching function, since NULL is macro. 
		           //C++ introduced nullptr to avoid confusion.
	}
	
3)initializer list and uniform initialization: 
  //uniform initialization: assignment operator is overhead: first resolve right hand side then
//allocate memory. So need uniform way of initialization.

	//Uniform initialization syntax:
	std::vector<int> v { 1, 2, 3 };
    std::map<int, std::string> m { {1, "one"}, { 2, "two" }};
	int* arr2 = new int[3]{ 1, 2, 3 };  //dynamic allocated array.
	int arr1[3] { 1, 2, 3 }; //array 
	int i { 42 }; //Built-in types
	//user defined types....
	class foo
        {
          int a_;
          double b_;
        public:
          foo():a_(0), b_(0) {}
          foo(int a, double b = 0.0):a_(a), b_(b) {}
        };

        foo f1{}; 
        foo f2{ 42, 1.2 }; 
        foo f3{ 42 };
         
	

//uniform initialization search order:
	//initializer_list constructor: myclass(const initializer_list<int>&v){}
		//all stl container supports initializer list constructor.
	//regular constructor that takes appropriate parameters myclass(int x, int y, int z): follows member by member copy
	//Aggregate initializer => myclass m ={1, 2, 3}; it does byte by byte copy
	
	//Ex: int *pi = new int[5]{1, 2, 3, 4, 5};
	//std::vector v1{1, 2};
	
	//Test code: 
	
	
	// vector<int> vec{10,20,20}; //calling initializer list constructor. 
	//Need not to store data using vec.push_back().
	//we can create our own initializer list constructor
	class myclass
	//{
	vector<int>m_vec;
	public:
		myclass(const initializer_list<int>&v)
		{
			for(initializer_list<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
			{
				m_vec.push_back(*itr);
			}
		}

	};
	int main()
	{
		myclass v {1,2,3,4};
	}
	Use of initializer list: It is used when:
	1)	To initialize reference variable
	2)	To initialize const variable
	3)	When object of one class is created in other class (required, otherwise default constructor of that class is called and if that is not implemented then there will be an error). 
	Ex: 
	class A 
	{ 
		int i,j; 
	public: 
		A(int, int ); 
	}; 

	A::A(int arg1, int arg2) { 
		i = arg1; 
		j = arg2;
		cout << "A's Constructor called: Value of i: " << i << endl; 
	} 

	// Class B contains object of A 
	class B { 
		A a; 
	public: 
		B(int, int ); 
	}; 

	B::B(int x, int y): a(x, y){ //Initializer list must be used, otherwise it will try to call default constructor of class A.
		cout << "B's Constructor called"; 
	} 

	int main() { 
		B obj(10,20); 
		return 0; 
	}
	4)	To initialize the members of Base class.
	Ex:
	#include <iostream> 
	using namespace std; 

	class A { 
		int i; 
	public: 
		A(int ); 
	}; 

	A::A(int arg) { 
		i = arg; 
		cout << "A's Constructor called: Value of i: " << i << endl; 
	} 

	// Class B is derived from A 
	class B: A { 
	public: 
		B(int ); 
	}; 

	B::B(int x):A(x) { //Initializer list must be used 
		cout << "B's Constructor called"; 
	} 

	int main() { 
		B obj(10); 
		return 0; 
	}
	5)	To initialize base class data members if function parameter and data member are using same name.

4)Range-based for loop: C++11 bring in a new kind of for loop that iterates over all elements of a given range/set of arrays or collection
	for (declaration : coll/array_name )
	{
	// statement(s) block;
	}
	Ex: 1
	for ( int i : { 2, 4, 6, 8, 10, 12, 14, 16 } )
	{
	std:: cout << "The Value :" << i << std:: endl;
	}
	Ex: 2
	std:: vector<int> vect = {10,2,3,4};
	for(auto & element :vect)
	{
			std::cout<<"element"<<element<<std::endl;
	}

5)constexpr: By specifying constexpr, we suggest compiler to evaluate value at compile time. 
	int gfun() { return 4;}

	int main()
	{
		int arr[gfun()]; //error: function call must have constant value....
		return 0;
	}
	solution is constexpr:
	constexpr int gfun() { return 4;}

	int main()
	{
		int arr[gfun()]; //error: function call must have constant value....
		return 0;
	}
		
	1)constexpr variables: The primary difference between const and constexpr variables is that the 
	initialization of a const variable can be deferred until run time. A constexpr variable must 
	be initialized at compile time.
	constexpr float x = 42.0;
	constexpr float y{108};
	constexpr float z = exp(5, 3);
	2)constexpr functions:A constexpr function is one whose return value is computable at compile time 
	when consuming code requires it.
	constexpr int product(int x, int y) 
	{ 
		return (x * y); 
	} 
	int main() 
	{ 
		const int x = product(10, 20); 
		cout << x; 
		return 0; 
	} 
	
6)Functors and lambda function:
Functors: Calling object using parenthesis like function call. 
One advantage of functors over function pointers is that they can hold state. 
Since this state is held by the instance of the object it can be thread safe 
(unlike static variables inside functions used with function pointers). 
The state of a functor can be initialized at construction.

function pointer can not have additional value/state:
void print(int val)
{
    cout<<"val="<<val<<"\n";
}

int main()
{
    vector<int>vec{10, 20, 30, 40};
    for_each(vec.begin(), vec.end(), print); //we can pass only parameter but not additional value.
    return 0;
}
***************************functors_example********
#include<iostream>
#include <vector>
#include<algorithm>	
using namespace std;

//Implemented functor using struct multiply

struct multiply
{
	private:
	int factor;
	public:
	multiply(){}
	multiply(int x):factor(x){}
	void operator()(int y)
	{
		cout<<"Multiplied vector values:"<<factor*y<<endl;
	}
	
};

//Implemented functor using class multiply

class multiply
{
	private:
		int factor;
	public:
	multiply(){}
	multiply(int x):factor(x){}
	void operator()(int y)
	{
		cout<<"Multiplied vector values:"<<factor*y<<endl;
	}
	
};


int main()
{
	vector<int>vec = {1,2,3,4};
	int factor = 2;
	//for_each(vec.begin(), vec.end(), multiply(2)); //calling functor(multiply(x)--> value will be passed to constructor)
	//using lambda function
	for_each(vec.begin(), vec.end(), [factor](int y){ //[] will take local variable and () will take vector values
	cout<<"Multiplied vector values:"<<factor*y<<endl;});
	return 0;
}
//A 'Lambda' function: A lambda is an unnamed function that is useful (in actual programming, not theory) 
//for short snippets of code that are impossible to reuse and are not worth naming.

syntax: [ capture clause ] (parameters) -> return-type //return type is evaluated by compiler 
		{   
			definition of method   
		} 

int main()
  {
      auto sum = [](int x, int y) { return x + y; };
      cout << sum(5, 2) << endl;
      cout << sum(10, 5) << endl;
  }

//C++ 14 provided generic lambda, suppose you want to have sum function for integer/float etc.
[](auto a, auto b) { return a + b; }

int main() 
{ 
  
    // Declare a generalized lambda and store it in sum 
    auto sum = [](auto a, auto b) { 
        return a + b; 
    }; 
  
    // Find sum of two integers 
    cout << sum(1, 6) << endl; 
  
    // Find sum of two floating numbers 
    cout << sum(1.0, 5.6) << endl; 
  
    // Find sum of two strings 
    cout << sum(string("Geeks"), string("ForGeeks")) << endl; 
  
    return 0; 
} 

/*

	  A lambda expression can have more power than an ordinary function by having 
	  access to variables from the enclosing scope. We can capture external variables
	  from enclosing scope by three ways : 
      Capture by reference 
      Capture by value 
      Capture by both (mixed capture)
	  Syntax used for capturing variables : 
      [&] : capture all external variable by reference--->
			
			int main()
			{
   			   int i = 3;
			   int j = 5;

			   // The following lambda expression captures i by value and
			   // j by reference.
			   function<int (void)> f = [&i, &j] { return i + j; };

			   // Change the values of i and j.
			   i = 22;
			   j = 44;

			   // Call f and print its result.
			   cout << f() << endl;
			} O/P: 66
		
      [=] : capture all external variable by value--->
			
			int main()
			{
				int i = 3;
				int j = 5;

				// The following lambda expression captures all external values
				auto f = [=] { return i + j; };

				// Call f and print its result.
				cout << f() << endl;
}
			
      [a, &b] : capture a by value and b by reference--->
				int main()
				{
					int i = 3;
					int j = 5;

					// The following lambda expression captures i by value and
					// j by reference.
					function<int (void)> f = [i, &j] { return i + j; };
					// Change the values of i and j.
					i = 22;
					j = 44;
					// Call f and print its result.
					cout << f() << endl;
				}
				O/P: 47
				
	  A lambda with empty capture clause [ ] can access only those variable which are local to it. 
      Capturing ways are demonstrated below :
 
*/


7)Deleted and Defaulted Functions: The default part instructs the compiler to generate the default implementation for
  the function. Defaulted functions have two advantages: 
  They are more efficient than manual implementations, and they rid the programmer from the chore 
  of defining those functions manually.
  struct A
	{
		A()=default; //C++11
		virtual ~A()=default; //C++11
	};
  The opposite of a defaulted function is a deleted function:
  int func()=delete;
  Deleted functions are useful for preventing object copying, among the rest. 
  Recall that C++ automatically declares a copy constructor and an assignment operator for classes. 
  To disable copying, declare these two special member functions =delete:
  class A {
	public:
    A(int x): m(x)
    {
    }
     
    // Delete the copy constructor
    A(const A&) = delete;
     
    // Delete the copy assignment operator
    A& operator=(const A&) = delete;
    int m;
};

8)Delegating Constructors: In C++11 a constructor may call another constructor of the same class:
	// Constructor delegation
    A(int z) : A()
    {
        this->z = z; // Only update z
    }

9)Override and Final:
	class B 
	{
	public:
	   virtual void f(int) const {std::cout << "B::f " << std::endl;}
	};

	class D : public B
	{
	public:
	   virtual void f(int) {std::cout << "D::f" << std::endl;}
	};
	int main()
	{
		B *b = new D();
		b->f(1); --> this will call base class f() not derived class f(). Since derive class function is not overriding the base class function. Both the functions are different in signature.
	}

	//if we want to avoid such situation, we will declare derive class function as override, now compiler will give you an error here. 
	Example with override implementation:
	class B 
	{
	public:
	   virtual void f(int) const 
	   {std::cout << "B::f " << std::endl;}
	};

	class D : public B
	{
	public:
	   virtual void f(int) override 
	   {std::cout << "D::f" << std::endl;}
	};
	//if you intend to make a method impossible to override any more (down the hierarchy), 
	//mark it as final. 
	
	class B 
	{
	public:
	   virtual void f(int) final //Freezed member-function, can not be overridden in sub-class
	   {std::cout << "B::f " << std::endl;}
	};

	class D : public B
	{
	public:
	   virtual void f(int)  
	   {std::cout << "D::f" << std::endl;}
	};
	
	That can be in the base class, or any derived class. 
	If it's in a derived class, you can use both the override and final specifiers.
	
10) Variadic template: are class or function templates, that can take any variable(zero or more)
	number of arguments. In C++, templates can have a fixed number of parameters only that have to be specified
	at the time of declaration. However, variadic templates help to overcome this issue.
	/* Syntax
	template(typename arg, typename... args)
	return_type function_name(arg var1, args... var2)
	*/
	#include <iostream>
	using namespace std;

	// To handle base case of below recursive
	// Variadic function Template
	template <typename T>
	T add(T var1)
	{
		return var1;
	}

	// Variadic function Template that takes
	// variable number of arguments 
	template <typename T, typename... Types>
	T add(T var1, Types... var2)
	{
		return var1 + add(var2...);
	}

	// Driver code
	int main()
	{
		cout<<add(1, 2, 3, 4)<<endl;
		return 0;
	}

11) Strongly typed Enums:

problems with existing enums:
enum apple{green =0, red =1};
enum orange{big =0, small =1};
int main()
{
	apple a = green;
	orange o = big;
	if(a ==o) //this becomes true while both enum type is not of same type. it is compared
	 //at compile time.
	{
		cout<<"true"<<endl;
	}
}
//solution is: Strongly typed Enums:
enum class apple{green =0, red =1};
enum class orange{big =0, small =1};
int main()
{
	apple a = apple::green;
	orange o = orange::big;
	if(typeid(a) == typeid(o))
	{
		cout<<"true"<<endl;
	}
}

12) Static_Assert:
int main()
{
	int* ptr = NULL;
	assert(ptr != NULL); //Run-time assert
	static_assert(sizeof(int)==8, "Not 32-bit"); //compile-time assert(C++11)
}





//Reference collapsing:


//Constexpr and static_assert:
constexpr int add(int x, int y){return x+y;}
static_assert(add(2,2)==4, "Not correct value")


   


	
		 
	 
