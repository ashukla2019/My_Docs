/*Void pointers: A void pointer is a pointer that has no associated data type with it. 
A void pointer can hold address of any type and can be typecasted to any type. 
*/

//void pointer cannot be dereferenced:
 
#include <iostream>;
using namespace std;
 
int main()
{
    int a = 10;
    void* ptr = &a;
   
    cout << *ptr; //error: 'void*' is not a pointer-to-object type 
   
    return 0;
}

//The C standard doesn’t allow pointer arithmetic with void pointers:
int main()
{
    int a[2] = {1, 2};
    void *ptr = &a;
    ptr = ptr + sizeof(int);
    printf("%d", *(int *)ptr);
    return 0;
}

//Pointer operations:
1) Increment/Decrement of a Pointer: 
	 // Incrementing pointer ptr1: ptr1++
	 // Decrementing pointer ptr1: ptr1--
2) Addition of integer to a pointer: When a pointer is added with a value, the value is first
   multiplied by the size of data type and then added to the pointer.
   ptr2 = ptr2 + 3; //will increase address by 3 pointer value.

3) Subtraction of integer to a pointer: When a pointer is subtracted with a value, 
   the value is first multiplied by the size of the data type and then subtracted from the pointer.
   ptr2 = ptr2 - 3; //will decrease address by 3 pointer value.
   
4) Subtracting two pointers of the same type: The subtraction of two pointers is possible only
   when they have the same data type. The result is generated by calculating the difference
   between the addresses of the two pointers
   x = ptr2 - ptr1; //will give difference b/w two address
   
5) Comparison of pointers of the same type: We can compare the two pointers by using the
   comparison operators in C. We can implement this by using all operators in C >,
   >=, <, <=, ==, !=.  It returns true for the valid condition and returns false
   for the unsatisfied condition. 
   if(*p1<*p2)
   
//Function pointers: pointer to function
	1) fun_ptr is a pointer to function fun() 
		void (*fun_ptr)(int) = &fun;
  
		/* The above line is equivalent of following two
		void (*fun_ptr)(int);
		fun_ptr = &fun; 
		*/
  
		// Invoking fun() using fun_ptr
		(*fun_ptr)(10);
	
	2) Like normal pointers, we can have an array of function pointers:
	   // fun_ptr_arr is an array of function pointers
	   void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	   //we can call array of function pointers:
	   (*fun_ptr_arr[ch])(a, b);
	
