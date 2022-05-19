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

1)Auto: Automatic Type Deduction
	//Before C++11, the auto keyword was used for storage class.
	//auto is now a sort of placeholder for a type, telling the compiler it has to deduce the actual type 
	//of a variable that is being declared from its initializer. 
	auto i = 42;        // i is an int
	auto l = 42LL;      // l is an long long
	auto p = new foo(); // p is a foo*

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
	
3)initializer list: assignment operator is overhead: first resolve right hand side then
//allocate memory. So need uniform way of initialization

//uniform initialization search order:
	//initializer_list constructor: myclass(const initializer_list<int>&v){}
		//all stl container supports initializer list constructor.
	//regular constructor that takes appropriate parameters myclass(int x, int y, int z): follows member by member copy
	//Aggregate initializer => myclass m ={1, 2, 3}; it does byte by byte copy
	
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

6)Deleted and Defaulted Functions: The default part instructs the compiler to generate the default implementation for
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

8) Delegating Constructors: In C++11 a constructor may call another constructor of the same class:

9) Override and Final:
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
	   virtual void f(int) const {std::cout << "B::f " << std::endl;}
	};

	class D : public B
	{
	public:
	   virtual void f(int) override {std::cout << "D::f" << std::endl;}
	};
	if you intend to make a method impossible to override any more (down the hierarchy), mark it as final. That can be in the base class, or any derived class. 
	If it's in a derived class, you can use both the override and final specifiers.
	
10) Variadic template: are class or function templates, that can take any variable(zero or more) number
	of arguments. In C++, templates can have a fixed number of parameters only that have to be specified
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

//Reference collapsing:




   


	
		 
	 
