/*
A structure is a collection of one or more variables, possibly of different types,
grouped under a single name. It is a user-defined data type.

*/
struct Point
{
	int x, y;
};

int main()
{
	// A valid initialization. member x gets value 0 and y
	// gets value 1. The order of declaration is followed.
	struct Point p1 = {0, 1};
}

//What is designated Initialization? 
//Designated Initialization allows structure members to be initialized in any order.
#include<stdio.h>

struct Point
{
int x, y, z;
};

int main()
{
	// Examples of initialization using designated initialization
	struct Point p1 = {.y = 0, .z = 1, .x = 2};
	struct Point p2 = {.x = 20};

	printf ("x = %d, y = %d, z = %d\n", p1.x, p1.y, p1.z);
	printf ("x = %d", p2.x);
	return 0;
}

//What is an array of structures? 
#include<stdio.h>

struct Point
{
	int x, y;
};

int main()
{
	// Create an array of structures
	struct Point arr[10];

	// Access array members
	arr[0].x = 10;
	arr[0].y = 20;

	printf("%d %d", arr[0].x, arr[0].y);
	return 0;
}

//What is a structure pointer? 
#include<stdio.h>

struct Point
{
	int x, y;
};

int main()
{
	struct Point p1 = {1, 2};

	// p2 is a pointer to structure p1
	struct Point *p2 = &p1;

	// Accessing structure members using structure pointer
	printf("%d %d", p2->x, p2->y);
	return 0;
}

/*
structure padding and packing:
Struct abc
{
	char a; //1byte
	int b; //4 byte
};

Memory is not byte addressable, it's word addressable. Size of word is 4 bytes in case of
32 bit machine and 8 bytes in case of 64 bit machine. In one cpu cycle, 1 word memory will be 
accessed. If we talk about above case, CPU will read integer value in 2 cpu cycle.
We can pad 3 bytes after 1 byte of character and total size of structure 
would be 8 bytes. compiler will insert padding bits.

struct abc
{
	char a; //1byte
	int b; //4 byte
	char c; //1 byte
};
total size of struct would be now 12 bytes.

//structure packing: is required to avoid adding extra padding bytes.
#pragma pack(1) -> will instruct compiler to pack structure members with particular 
alignment.
 