Pointers in C:

Data_Type * Pointer_Name;(pointer holds the address of variables)

NULL pointer:A Null Pointer is a pointer that does not point to any memory location.

Wild pointer:A pointer that is not initialized properly before its first use is known as the wild pointer.

Dangling pointer: daggling pointers arise when the referencing object is deleted or deallocated, 
without changing the value of the pointers. It creates the problem because the pointer is still
pointing to the memory that is not available.

const int a;      ->  The “a” is a constant integer.
int const a;      ->  The “a” is a constant integer.
const int *a;     ->  Here “a” is a pointer to a const integer, the value of the integer is not modifiable, 
                       but the pointer is modifiable.
int * const a;    ->  Here “a” is a const pointer to an integer, the value of the pointed integer is modifiable,
                      but the pointer is not modifiable.
int const * a const; -> both constant.

Advantage of pointers in C:
We can access the memory location with the help of C Pointers.
With the help of pointers, we can efficiently pass the structure. It helps to reduce stack usage.

Dereference Operator ( * ): It is a unary operator that is used in the declaration of the pointer and accesses a value indirectly,
through a pointer.

address of operator ( &): It is also a unary operator and gives the address of the operand.

Segmentation fault: A segmentation fault is a common problem that causes programs to crash. 
A core file (core dumped file) also associated with a segmentation fault that is used by the 
developer to finding the root cause of the crashing (segmentation fault).
Generally, the segmentation fault occurs when a program tried to access a memory location 
that is not allowed to access or tried to access a memory location in a way that is not 
allowed (tried to access read-only memory).

Difference between Segmentation fault and Bus error: 
Segmentation fault occurs in below scenario:
When trying to de-referencing a NULL pointer.
Trying to access memory which is already de-allocated (trying to use dangling pointers).
Using uninitialized pointer(wild pointer).
Trying to access memory that the program doesn’t own. 

Stack overflow:If your program tries to access beyond the limit of the available stack memory then stack overflow
occurs.

Output of the below programs:
#include <stdio.h>
int main(void)
{
    int aiData[5] = {100,200,300,400,500};
    
    int *piData = aiData;
    
    ++*piData;
    
    printf("aiData[0] = %d, aiData[1] = %d, *piData = %d", aiData[0], aiData[1], *piData);
    
    return 0;
}
Output: 101 , 200 , 101

#include <stdio.h>
int main(void)
{
    int aiData[5] = {100,200,30,40,50};
    
    int *piData = aiData;
    
    *++piData;
    
    printf("aiData[0] = %d, aiData[1] = %d, *piData = %d", aiData[0], aiData[1], *piData);
    
    return 0;
}
Output: 100, 200, 200


A memory leak is a common and dangerous problem. It is a type of resource leak. 
In C language, a memory leak occurs when you allocate a block of memory using the memory management 
function and forget to release it.

int main ()
{
    char * pBuffer = malloc(sizeof(char) * 20);
    /* Do some work */
    return 0; /*Not freeing the allocated memory*/
}

output of program:
#include<stdio.h>
void fun(int *p)
{
  int q = 40;
  p = &q;
}
int main()
{
  int data = 27;
  int *ptr = &data;
  fun(ptr);
  printf("%d", *ptr);
  return 0;
}
Output:27

#include<stdio.h>
void fun(int **p)
{
  static int q = 40;
  *p = &q;
}
int main()
{
  int data = 27;
  int *ptr = &data;
  fun(&ptr);
  printf("%d", *ptr);
  return 0;
}
Output: 40

#include <stdio.h>
int main()
{
   int (*ptr)[5][10];
   printf("%d",  sizeof(*ptr));
   return 0;
}

Output: 200

void fun(char** ptr)
{
    ptr++;
}
int main()
{
    char *str = malloc(20*sizeof(char));
    if(str == NULL)
        return -1;
    strcpy(str, "Aticleworld");
    fun(&str);
    puts(str);
    free(str);
    return 0;
}
Output: Aticleworld

void fun(char** ptr)
{
    (*ptr)++;
}
int main()
{
    char *str = malloc(20*sizeof(char));
    if(str == NULL)
        return -1;
    strcpy(str, "Aticleworld");
    fun(&str);
    puts(str);
    free(str);
    return 0;
}
Output: ticleworld

  